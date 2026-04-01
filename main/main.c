#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/i2c_master.h"
#include "driver/uart.h"
#include "esp_log.h"

#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_io_i80.h"
#include "esp_lcd_st7796.h"

#include "esp_lcd_touch.h"
#include "esp_lcd_touch_ft5x06.h"

#include "lvgl.h"
#include "esp_lvgl_port.h"

LV_FONT_DECLARE(rus20);
LV_FONT_DECLARE(rus24);
LV_FONT_DECLARE(rus30);

#define LCD_H_RES                  480
#define LCD_V_RES                  320
#define LCD_BYTES_PER_PIXEL        2

#define PIN_NUM_LCD_BL             45
#define PIN_NUM_LCD_RST            4
#define PIN_NUM_LCD_DC             0
#define PIN_NUM_LCD_WR             47

#define PIN_NUM_LCD_D0             9
#define PIN_NUM_LCD_D1             46
#define PIN_NUM_LCD_D2             3
#define PIN_NUM_LCD_D3             8
#define PIN_NUM_LCD_D4             18
#define PIN_NUM_LCD_D5             17
#define PIN_NUM_LCD_D6             16
#define PIN_NUM_LCD_D7             15

#define PIN_NUM_TOUCH_SCL          5
#define PIN_NUM_TOUCH_SDA          6
#define PIN_NUM_TOUCH_INT          7

#define LCD_DRAW_BUF_LINES         40
#define LCD_PIXEL_CLOCK_HZ         (10 * 1000 * 1000)

#define FONT_MAIN  (&rus20)
#define FONT_TITLE (&rus20)
#define FONT_VALUE (&rus24)
#define FONT_SMALL (&rus20)
#define FONT_BIG   (&rus30)

#define MB_UART_NUM                UART_NUM_1
#define MB_RXD_PIN                 1
#define MB_RTS_PIN                 2
#define MB_TXD_PIN                 42

#define MB_SLAVE_ADDR              1
#define MB_BAUD_RATE               9600
#define MB_RX_BUF_SIZE             256
#define MB_TX_BUF_SIZE             256

/* 0..6 old regs, 7..62 weekly schedule (28 times * 2 words) */
#define MB_REG_COUNT               63

#define TIMER_STEP_SEC             900U
#define DAY_SEC                    86400U

static const char *TAG = "CLIMATE_UI";

static uint16_t status_flags = 0x0001;
static portMUX_TYPE reg_lock = portMUX_INITIALIZER_UNLOCKED;

static esp_lcd_panel_handle_t panel_handle = NULL;
static esp_lcd_panel_io_handle_t lcd_io_handle = NULL;
static esp_lcd_touch_handle_t tp = NULL;
static lv_display_t *disp = NULL;
static lv_indev_t *touch_indev = NULL;

/* -------- app state -------- */
/* temperatures are stored in tenths: 20.0 C = 200, 100.1 C = 1001 */
static int16_t room_temp = 400;
static int16_t room_hum = 40;
static int16_t duct_temp = 200;
static int16_t co2_ppm = 1750;

static int16_t temp_setpoint = 400;
static int16_t hum_setpoint = 40;

/* -------- weekly schedule -------- */
/* times are stored in seconds from start of day:
 * 17:30 = 63000
 * 21:00 = 75600
 */
typedef struct {
    uint32_t on1_s;
    uint32_t off1_s;
    uint32_t on2_s;
    uint32_t off2_s;
} day_schedule_t;

static day_schedule_t week_schedule[7] = {
    {63000, 75600,     0,     0},   /* Mon */
    {63000, 75600,     0,     0},   /* Tue */
    {63000, 75600,     0,     0},   /* Wed */
    {63000, 75600,     0,     0},   /* Thu */
    {63000, 75600,     0,     0},   /* Fri */
    {    0,     0,     0,     0},   /* Sat */
    {    0,     0,     0,     0},   /* Sun */
};

static uint8_t selected_day = 0;
static const char *day_names[7] = {
    "ПН", "ВТ", "СР", "ЧТ", "ПТ", "СБ", "ВС"
};

/* -------- UI refs main -------- */
static lv_obj_t *screen_main = NULL;
static lv_obj_t *screen_schedule = NULL;

static lv_obj_t *lbl_room_temp = NULL;
static lv_obj_t *lbl_room_hum = NULL;
static lv_obj_t *lbl_duct_temp = NULL;
static lv_obj_t *lbl_co2 = NULL;
static lv_obj_t *lbl_temp_set = NULL;
static lv_obj_t *lbl_hum_set = NULL;
static lv_obj_t *lbl_mode = NULL;
static lv_obj_t *lbl_status = NULL;

/* value boxes */
static lv_obj_t *box_room_temp = NULL;
static lv_obj_t *box_room_hum = NULL;
static lv_obj_t *box_duct_temp = NULL;
static lv_obj_t *box_co2 = NULL;
static lv_obj_t *box_temp_set = NULL;
static lv_obj_t *box_hum_set = NULL;

/* -------- UI refs schedule -------- */
static lv_obj_t *lbl_day_name = NULL;
static lv_obj_t *lbl_on1 = NULL;
static lv_obj_t *lbl_off1 = NULL;
static lv_obj_t *lbl_on2 = NULL;
static lv_obj_t *lbl_off2 = NULL;

/* -------- styles -------- */
static lv_style_t style_topbar;
static lv_style_t style_panel_big;
static lv_style_t style_panel_small;
static lv_style_t style_setpanel;
static lv_style_t style_value_box;
static lv_style_t style_text_normal;
static lv_style_t style_text_temp;
static lv_style_t style_text_hum;
static lv_style_t style_text_small;
static lv_style_t style_btn;

/* -------- formatting helpers -------- */
static void fmt_temp_tenths(char *buf, size_t buf_size, int16_t value_tenths, bool with_unit)
{
    int16_t abs_val = (int16_t)abs(value_tenths);
    int16_t whole = abs_val / 10;
    int16_t frac = abs_val % 10;

    if (value_tenths < 0) {
        if (with_unit) {
            snprintf(buf, buf_size, "-%d.%d C", whole, frac);
        } else {
            snprintf(buf, buf_size, "-%d.%d", whole, frac);
        }
    } else {
        if (with_unit) {
            snprintf(buf, buf_size, "%d.%d C", whole, frac);
        } else {
            snprintf(buf, buf_size, "%d.%d", whole, frac);
        }
    }
}

static void fmt_time_hhmm(char *buf, size_t buf_size, uint32_t sec)
{
    uint32_t hh = sec / 3600U;
    uint32_t mm = (sec % 3600U) / 60U;
    snprintf(buf, buf_size, "%02lu:%02lu",
             (unsigned long)hh,
             (unsigned long)mm);
}

static uint32_t time_add_step_sec(uint32_t t, int32_t delta_sec)
{
    int32_t v = (int32_t)t + delta_sec;

    while (v < 0) {
        v += (int32_t)DAY_SEC;
    }
    while (v >= (int32_t)DAY_SEC) {
        v -= (int32_t)DAY_SEC;
    }

    return (uint32_t)v;
}

static uint32_t *schedule_point_ptr(uint8_t day, uint8_t point)
{
    if (day > 6 || point > 3) return NULL;

    switch (point) {
        case 0: return &week_schedule[day].on1_s;
        case 1: return &week_schedule[day].off1_s;
        case 2: return &week_schedule[day].on2_s;
        case 3: return &week_schedule[day].off2_s;
        default: return NULL;
    }
}

/* -------- hardware init -------- */
static void board_backlight_on(void)
{
    gpio_config_t bk_gpio = {
        .pin_bit_mask = 1ULL << PIN_NUM_LCD_BL,
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = 0,
        .pull_down_en = 0,
        .intr_type = GPIO_INTR_DISABLE,
    };
    ESP_ERROR_CHECK(gpio_config(&bk_gpio));
    ESP_ERROR_CHECK(gpio_set_level(PIN_NUM_LCD_BL, 1));
}

static void board_shared_reset_pulse(void)
{
    gpio_config_t rst_gpio = {
        .pin_bit_mask = 1ULL << PIN_NUM_LCD_RST,
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = 0,
        .pull_down_en = 0,
        .intr_type = GPIO_INTR_DISABLE,
    };
    ESP_ERROR_CHECK(gpio_config(&rst_gpio));

    ESP_ERROR_CHECK(gpio_set_level(PIN_NUM_LCD_RST, 0));
    vTaskDelay(pdMS_TO_TICKS(20));
    ESP_ERROR_CHECK(gpio_set_level(PIN_NUM_LCD_RST, 1));
    vTaskDelay(pdMS_TO_TICKS(120));
}

static void lcd_init(void)
{
    esp_lcd_i80_bus_handle_t i80_bus = NULL;

    esp_lcd_i80_bus_config_t bus_config = {
        .dc_gpio_num = PIN_NUM_LCD_DC,
        .wr_gpio_num = PIN_NUM_LCD_WR,
        .clk_src = LCD_CLK_SRC_DEFAULT,
        .data_gpio_nums = {
            PIN_NUM_LCD_D0,
            PIN_NUM_LCD_D1,
            PIN_NUM_LCD_D2,
            PIN_NUM_LCD_D3,
            PIN_NUM_LCD_D4,
            PIN_NUM_LCD_D5,
            PIN_NUM_LCD_D6,
            PIN_NUM_LCD_D7,
        },
        .bus_width = 8,
        .max_transfer_bytes = LCD_H_RES * LCD_DRAW_BUF_LINES * LCD_BYTES_PER_PIXEL,
        .psram_trans_align = 64,
        .sram_trans_align = 4,
    };
    ESP_ERROR_CHECK(esp_lcd_new_i80_bus(&bus_config, &i80_bus));

    esp_lcd_panel_io_i80_config_t io_config = {
        .cs_gpio_num = -1,
        .pclk_hz = LCD_PIXEL_CLOCK_HZ,
        .trans_queue_depth = 10,
        .dc_levels = {
            .dc_idle_level = 0,
            .dc_cmd_level = 0,
            .dc_dummy_level = 0,
            .dc_data_level = 1,
        },
        .lcd_cmd_bits = 8,
        .lcd_param_bits = 8,
    };
    ESP_ERROR_CHECK(esp_lcd_new_panel_io_i80(i80_bus, &io_config, &lcd_io_handle));
    assert(lcd_io_handle != NULL);

    esp_lcd_panel_dev_config_t panel_config = {
        .reset_gpio_num = -1,
        .rgb_ele_order = LCD_RGB_ELEMENT_ORDER_RGB,
        .bits_per_pixel = 16,
    };
    ESP_ERROR_CHECK(esp_lcd_new_panel_st7796(lcd_io_handle, &panel_config, &panel_handle));
    assert(panel_handle != NULL);

    ESP_ERROR_CHECK(esp_lcd_panel_reset(panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_init(panel_handle));

    ESP_ERROR_CHECK(esp_lcd_panel_invert_color(panel_handle, true));
    ESP_ERROR_CHECK(esp_lcd_panel_mirror(panel_handle, false, false));
    ESP_ERROR_CHECK(esp_lcd_panel_swap_xy(panel_handle, false));
    ESP_ERROR_CHECK(esp_lcd_panel_disp_on_off(panel_handle, true));

    ESP_LOGI(TAG, "LCD ready");
}

static void touch_init(void)
{
    i2c_master_bus_handle_t i2c_bus = NULL;

    const i2c_master_bus_config_t bus_config = {
        .i2c_port = I2C_NUM_0,
        .sda_io_num = PIN_NUM_TOUCH_SDA,
        .scl_io_num = PIN_NUM_TOUCH_SCL,
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 7,
        .flags.enable_internal_pullup = true,
    };
    ESP_ERROR_CHECK(i2c_new_master_bus(&bus_config, &i2c_bus));

    const esp_lcd_panel_io_i2c_config_t tp_io_config =
        ESP_LCD_TOUCH_IO_I2C_FT5x06_CONFIG();

    esp_lcd_panel_io_handle_t tp_io_handle = NULL;
    ESP_ERROR_CHECK(esp_lcd_new_panel_io_i2c(i2c_bus, &tp_io_config, &tp_io_handle));

    const esp_lcd_touch_config_t tp_cfg = {
        .x_max = LCD_V_RES,
        .y_max = LCD_H_RES,
        .rst_gpio_num = -1,
        .int_gpio_num = PIN_NUM_TOUCH_INT,
        .levels = {
            .reset = 0,
            .interrupt = 0,
        },
        .flags = {
            .swap_xy = 1,
            .mirror_x = 1,
            .mirror_y = 0,
        },
    };

    ESP_ERROR_CHECK(esp_lcd_touch_new_i2c_ft5x06(tp_io_handle, &tp_cfg, &tp));
    assert(tp != NULL);

    ESP_LOGI(TAG, "Touch ready");
}

/* -------- UI helpers -------- */
static void init_styles(void)
{
    lv_style_init(&style_topbar);
    lv_style_set_bg_color(&style_topbar, lv_color_hex(0x0C1828));
    lv_style_set_bg_opa(&style_topbar, LV_OPA_COVER);
    lv_style_set_border_width(&style_topbar, 1);
    lv_style_set_border_color(&style_topbar, lv_color_hex(0x223754));
    lv_style_set_radius(&style_topbar, 6);
    lv_style_set_pad_all(&style_topbar, 4);

    lv_style_init(&style_panel_big);
    lv_style_set_bg_color(&style_panel_big, lv_color_hex(0x101E31));
    lv_style_set_bg_opa(&style_panel_big, LV_OPA_COVER);
    lv_style_set_border_width(&style_panel_big, 1);
    lv_style_set_border_color(&style_panel_big, lv_color_hex(0x283E5C));
    lv_style_set_radius(&style_panel_big, 6);
    lv_style_set_pad_all(&style_panel_big, 6);

    lv_style_init(&style_panel_small);
    lv_style_set_bg_color(&style_panel_small, lv_color_hex(0x0D1B2C));
    lv_style_set_bg_opa(&style_panel_small, LV_OPA_COVER);
    lv_style_set_border_width(&style_panel_small, 1);
    lv_style_set_border_color(&style_panel_small, lv_color_hex(0x24384F));
    lv_style_set_radius(&style_panel_small, 6);
    lv_style_set_pad_all(&style_panel_small, 6);

    lv_style_init(&style_setpanel);
    lv_style_set_bg_color(&style_setpanel, lv_color_hex(0x0B1725));
    lv_style_set_bg_opa(&style_setpanel, LV_OPA_COVER);
    lv_style_set_border_width(&style_setpanel, 1);
    lv_style_set_border_color(&style_setpanel, lv_color_hex(0x213448));
    lv_style_set_radius(&style_setpanel, 6);
    lv_style_set_pad_all(&style_setpanel, 6);

    lv_style_init(&style_value_box);
    lv_style_set_bg_color(&style_value_box, lv_color_hex(0x08121D));
    lv_style_set_bg_opa(&style_value_box, LV_OPA_COVER);
    lv_style_set_border_width(&style_value_box, 1);
    lv_style_set_border_color(&style_value_box, lv_color_hex(0x2A3E58));
    lv_style_set_radius(&style_value_box, 4);
    lv_style_set_pad_all(&style_value_box, 2);

    lv_style_init(&style_text_normal);
    lv_style_set_text_color(&style_text_normal, lv_color_white());
    lv_style_set_text_font(&style_text_normal, FONT_TITLE);

    lv_style_init(&style_text_temp);
    lv_style_set_text_color(&style_text_temp, lv_color_hex(0xFFA21A));
    lv_style_set_text_font(&style_text_temp, FONT_BIG);

    lv_style_init(&style_text_hum);
    lv_style_set_text_color(&style_text_hum, lv_color_hex(0xAEE0FF));
    lv_style_set_text_font(&style_text_hum, FONT_BIG);

    lv_style_init(&style_text_small);
    lv_style_set_text_color(&style_text_small, lv_color_white());
    lv_style_set_text_font(&style_text_small, FONT_TITLE);

    lv_style_init(&style_btn);
    lv_style_set_bg_color(&style_btn, lv_color_hex(0x1B2A40));
    lv_style_set_bg_opa(&style_btn, LV_OPA_COVER);
    lv_style_set_radius(&style_btn, 4);
}

static lv_obj_t *create_panel(lv_obj_t *parent, int x, int y, int w, int h, lv_style_t *style)
{
    lv_obj_t *obj = lv_obj_create(parent);
    lv_obj_remove_style_all(obj);
    lv_obj_add_style(obj, style, 0);
    lv_obj_set_pos(obj, x, y);
    lv_obj_set_size(obj, w, h);
    return obj;
}

static lv_obj_t *create_value_box(lv_obj_t *parent, int x, int y, int w, int h)
{
    lv_obj_t *obj = lv_obj_create(parent);
    lv_obj_remove_style_all(obj);
    lv_obj_add_style(obj, &style_value_box, 0);
    lv_obj_set_pos(obj, x, y);
    lv_obj_set_size(obj, w, h);
    return obj;
}

static void refresh_values(void)
{
    char buf[24];

    if (lbl_room_temp) {
        fmt_temp_tenths(buf, sizeof(buf), room_temp, true);
        lv_label_set_text(lbl_room_temp, buf);
        lv_obj_center(lbl_room_temp);
    }

    if (lbl_room_hum) {
        lv_label_set_text_fmt(lbl_room_hum, "%d %%", room_hum);
        lv_obj_center(lbl_room_hum);
    }

    if (lbl_duct_temp) {
        fmt_temp_tenths(buf, sizeof(buf), duct_temp, true);
        lv_label_set_text(lbl_duct_temp, buf);
        lv_obj_center(lbl_duct_temp);
    }

    if (lbl_co2) {
        lv_label_set_text_fmt(lbl_co2, "%d ppm", co2_ppm);
        lv_obj_center(lbl_co2);
    }

    if (lbl_temp_set) {
        fmt_temp_tenths(buf, sizeof(buf), temp_setpoint, false);
        lv_label_set_text(lbl_temp_set, buf);
        lv_obj_center(lbl_temp_set);
    }

    if (lbl_hum_set) {
        lv_label_set_text_fmt(lbl_hum_set, "%d", hum_setpoint);
        lv_obj_center(lbl_hum_set);
    }
}

static void refresh_schedule_screen(void)
{
    char buf[16];

    if (lbl_day_name) {
        lv_label_set_text(lbl_day_name, day_names[selected_day]);
    }

    if (lbl_on1) {
        fmt_time_hhmm(buf, sizeof(buf), week_schedule[selected_day].on1_s);
        lv_label_set_text(lbl_on1, buf);
        lv_obj_center(lbl_on1);
    }
    if (lbl_off1) {
        fmt_time_hhmm(buf, sizeof(buf), week_schedule[selected_day].off1_s);
        lv_label_set_text(lbl_off1, buf);
        lv_obj_center(lbl_off1);
    }
    if (lbl_on2) {
        fmt_time_hhmm(buf, sizeof(buf), week_schedule[selected_day].on2_s);
        lv_label_set_text(lbl_on2, buf);
        lv_obj_center(lbl_on2);
    }
    if (lbl_off2) {
        fmt_time_hhmm(buf, sizeof(buf), week_schedule[selected_day].off2_s);
        lv_label_set_text(lbl_off2, buf);
        lv_obj_center(lbl_off2);
    }
}

static void set_status_text(const char *txt)
{
    if (lbl_status) lv_label_set_text(lbl_status, txt);
}

/* -------- main screen buttons -------- */
typedef enum {
    ACT_TEMP_MINUS,
    ACT_TEMP_PLUS,
    ACT_HUM_MINUS,
    ACT_HUM_PLUS,
} action_t;

static void btn_event_cb(lv_event_t *e)
{
    action_t action = (action_t)(intptr_t)lv_event_get_user_data(e);

    switch (action) {
        case ACT_TEMP_MINUS:
            temp_setpoint -= 5;
            if (temp_setpoint < 250) temp_setpoint = 250;
            set_status_text("T -");
            break;

        case ACT_TEMP_PLUS:
            temp_setpoint += 5;
            if (temp_setpoint > 400) temp_setpoint = 400;
            set_status_text("T +");
            break;

        case ACT_HUM_MINUS:
            hum_setpoint -= 1;
            if (hum_setpoint < 40) hum_setpoint = 40;
            set_status_text("RH -");
            break;

        case ACT_HUM_PLUS:
            hum_setpoint += 1;
            if (hum_setpoint > 60) hum_setpoint = 60;
            set_status_text("RH +");
            break;
    }

    refresh_values();
}

static lv_obj_t *create_pm_button(lv_obj_t *parent, const char *txt, int x, int y, action_t act)
{
    lv_obj_t *btn = lv_button_create(parent);
    lv_obj_set_size(btn, 40, 40);
    lv_obj_set_pos(btn, x, y - 5);
    lv_obj_add_style(btn, &style_btn, 0);
    lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_CLICKED, (void *)(intptr_t)act);

    lv_obj_t *label = lv_label_create(btn);
    lv_label_set_text(label, txt);
    lv_obj_set_style_text_font(label, FONT_TITLE, 0);
    lv_obj_set_style_text_color(label, lv_color_white(), 0);
    lv_obj_center(label);
    return btn;
}

/* -------- schedule screen buttons -------- */
typedef enum {
    SCH_DAY_PREV,
    SCH_DAY_NEXT,
    SCH_ON1_PLUS,
    SCH_ON1_MINUS,
    SCH_OFF1_PLUS,
    SCH_OFF1_MINUS,
    SCH_ON2_PLUS,
    SCH_ON2_MINUS,
    SCH_OFF2_PLUS,
    SCH_OFF2_MINUS,
    SCH_BACK
} schedule_action_t;

static void schedule_event_cb(lv_event_t *e)
{
    schedule_action_t act = (schedule_action_t)(intptr_t)lv_event_get_user_data(e);

    switch (act) {
        case SCH_DAY_PREV:
            selected_day = (selected_day == 0) ? 6 : (selected_day - 1);
            break;
        case SCH_DAY_NEXT:
            selected_day = (selected_day + 1) % 7;
            break;
        case SCH_ON1_PLUS:
            week_schedule[selected_day].on1_s =
                time_add_step_sec(week_schedule[selected_day].on1_s, +((int32_t)TIMER_STEP_SEC));
            break;
        case SCH_ON1_MINUS:
            week_schedule[selected_day].on1_s =
                time_add_step_sec(week_schedule[selected_day].on1_s, -((int32_t)TIMER_STEP_SEC));
            break;
        case SCH_OFF1_PLUS:
            week_schedule[selected_day].off1_s =
                time_add_step_sec(week_schedule[selected_day].off1_s, +((int32_t)TIMER_STEP_SEC));
            break;
        case SCH_OFF1_MINUS:
            week_schedule[selected_day].off1_s =
                time_add_step_sec(week_schedule[selected_day].off1_s, -((int32_t)TIMER_STEP_SEC));
            break;
        case SCH_ON2_PLUS:
            week_schedule[selected_day].on2_s =
                time_add_step_sec(week_schedule[selected_day].on2_s, +((int32_t)TIMER_STEP_SEC));
            break;
        case SCH_ON2_MINUS:
            week_schedule[selected_day].on2_s =
                time_add_step_sec(week_schedule[selected_day].on2_s, -((int32_t)TIMER_STEP_SEC));
            break;
        case SCH_OFF2_PLUS:
            week_schedule[selected_day].off2_s =
                time_add_step_sec(week_schedule[selected_day].off2_s, +((int32_t)TIMER_STEP_SEC));
            break;
        case SCH_OFF2_MINUS:
            week_schedule[selected_day].off2_s =
                time_add_step_sec(week_schedule[selected_day].off2_s, -((int32_t)TIMER_STEP_SEC));
            break;
        case SCH_BACK:
            if (screen_main) {
                lv_screen_load(screen_main);
            }
            return;
    }

    refresh_schedule_screen();
}

static void open_schedule_cb(lv_event_t *e)
{
    (void)e;
    refresh_schedule_screen();
    if (screen_schedule) {
        lv_screen_load(screen_schedule);
    }
}

static lv_obj_t *create_time_editor(lv_obj_t *parent, int x, int y,
                                    const char *title,
                                    lv_obj_t **out_label,
                                    schedule_action_t plus_act,
                                    schedule_action_t minus_act)
{
    lv_obj_t *cont = create_panel(parent, x, y, 420, 44, &style_panel_small);

    lv_obj_t *t = lv_label_create(cont);
    lv_label_set_text(t, title);
    lv_obj_set_style_text_font(t, FONT_TITLE, 0);
    lv_obj_set_style_text_color(t, lv_color_white(), 0);
    lv_obj_align(t, LV_ALIGN_LEFT_MID, 8, 0);

    lv_obj_t *btn_minus = lv_button_create(cont);
    lv_obj_set_size(btn_minus, 44, 30);
    lv_obj_set_pos(btn_minus, 170, 7);
    lv_obj_add_style(btn_minus, &style_btn, 0);
    lv_obj_add_event_cb(btn_minus, schedule_event_cb, LV_EVENT_CLICKED, (void *)(intptr_t)minus_act);

    lv_obj_t *lm = lv_label_create(btn_minus);
    lv_label_set_text(lm, "-");
    lv_obj_set_style_text_font(lm, FONT_TITLE, 0);
    lv_obj_set_style_text_color(lm, lv_color_white(), 0);
    lv_obj_center(lm);

    lv_obj_t *box = create_value_box(cont, 220, 7, 110, 30);
    *out_label = lv_label_create(box);
    lv_obj_set_style_text_font(*out_label, FONT_VALUE, 0);
    lv_obj_set_style_text_color(*out_label, lv_color_white(), 0);
    lv_obj_center(*out_label);

    lv_obj_t *btn_plus = lv_button_create(cont);
    lv_obj_set_size(btn_plus, 44, 30);
    lv_obj_set_pos(btn_plus, 338, 7);
    lv_obj_add_style(btn_plus, &style_btn, 0);
    lv_obj_add_event_cb(btn_plus, schedule_event_cb, LV_EVENT_CLICKED, (void *)(intptr_t)plus_act);

    lv_obj_t *lp = lv_label_create(btn_plus);
    lv_label_set_text(lp, "+");
    lv_obj_set_style_text_font(lp, FONT_TITLE, 0);
    lv_obj_set_style_text_color(lp, lv_color_white(), 0);
    lv_obj_center(lp);

    return cont;
}

/* -------- create screens -------- */
static void ui_create(void)
{
    lv_obj_t *scr = lv_screen_active();
    lv_obj_set_style_bg_color(scr, lv_color_hex(0x08121D), 0);

    init_styles();

    lv_obj_t *top = create_panel(scr, 8, 6, 464, 34, &style_topbar);

    lv_obj_t *sys = lv_label_create(top);
    lv_label_set_text(sys, "Приточная вентиляция");
    lv_obj_set_style_text_color(sys, lv_color_white(), 0);
    lv_obj_set_style_text_font(sys, FONT_TITLE, 0);
    lv_obj_align(sys, LV_ALIGN_LEFT_MID, 6, 0);

    lbl_mode = lv_label_create(top);
    lv_label_set_text(lbl_mode, "RUN");
    lv_obj_set_style_text_color(lbl_mode, lv_color_hex(0xFFA51E), 0);
    lv_obj_set_style_text_font(lbl_mode, FONT_TITLE, 0);
    lv_obj_align(lbl_mode, LV_ALIGN_CENTER, 20, 0);

    lbl_status = lv_label_create(top);
    lv_label_set_text(lbl_status, "OK");
    lv_obj_set_style_text_color(lbl_status, lv_color_white(), 0);
    lv_obj_set_style_text_font(lbl_status, FONT_TITLE, 0);
    lv_obj_align(lbl_status, LV_ALIGN_RIGHT_MID, -6, 0);

    lv_obj_t *btn_schedule = lv_button_create(top);
    lv_obj_set_size(btn_schedule, 92, 24);
    lv_obj_set_pos(btn_schedule, 358, 4);
    lv_obj_add_style(btn_schedule, &style_btn, 0);
    lv_obj_add_event_cb(btn_schedule, open_schedule_cb, LV_EVENT_CLICKED, NULL);

    lv_obj_t *lbl_sched = lv_label_create(btn_schedule);
    lv_label_set_text(lbl_sched, "ГРАФИК");
    lv_obj_set_style_text_font(lbl_sched, FONT_MAIN, 0);
    lv_obj_set_style_text_color(lbl_sched, lv_color_white(), 0);
    lv_obj_center(lbl_sched);

    lv_obj_t *p_temp = create_panel(scr, 8, 46, 228, 104, &style_panel_big);
    lv_obj_t *p_hum  = create_panel(scr, 244, 46, 228, 104, &style_panel_big);

    lv_obj_t *t1 = lv_label_create(p_temp);
    lv_label_set_text(t1, "Температура");
    lv_obj_set_style_text_font(t1, FONT_VALUE, 0);
    lv_obj_set_style_text_color(t1, lv_color_white(), 0);
    lv_obj_align(t1, LV_ALIGN_TOP_MID, 0, 0);

    box_room_temp = create_value_box(p_temp, 26, 38, 176, 52);
    lbl_room_temp = lv_label_create(box_room_temp);
    lv_obj_add_style(lbl_room_temp, &style_text_temp, 0);

    lv_obj_t *t2 = lv_label_create(p_hum);
    lv_label_set_text(t2, "Влажность");
    lv_obj_set_style_text_font(t2, FONT_VALUE, 0);
    lv_obj_set_style_text_color(t2, lv_color_white(), 0);
    lv_obj_align(t2, LV_ALIGN_TOP_MID, 0, 0);

    box_room_hum = create_value_box(p_hum, 26, 38, 176, 52);
    lbl_room_hum = lv_label_create(box_room_hum);
    lv_obj_add_style(lbl_room_hum, &style_text_hum, 0);

    lv_obj_t *p_duct = create_panel(scr, 8, 156, 228, 62, &style_panel_small);
    lv_obj_t *p_co2  = create_panel(scr, 244, 156, 228, 62, &style_panel_small);

    lv_obj_t *d1 = lv_label_create(p_duct);
    lv_label_set_text(d1, "Т-канал");
    lv_obj_set_style_text_font(d1, FONT_TITLE, 0);
    lv_obj_set_style_text_color(d1, lv_color_white(), 0);
    lv_obj_align(d1, LV_ALIGN_LEFT_MID, 6, -12);

    box_duct_temp = create_value_box(p_duct, 118, 10, 98, 40);
    lbl_duct_temp = lv_label_create(box_duct_temp);
    lv_obj_set_style_text_font(lbl_duct_temp, FONT_VALUE, 0);
    lv_obj_set_style_text_color(lbl_duct_temp, lv_color_white(), 0);

    lv_obj_t *c1 = lv_label_create(p_co2);
    lv_label_set_text(c1, "CO2");
    lv_obj_set_style_text_font(c1, FONT_TITLE, 0);
    lv_obj_set_style_text_color(c1, lv_color_white(), 0);
    lv_obj_align(c1, LV_ALIGN_LEFT_MID, 6, -12);

    box_co2 = create_value_box(p_co2, 80, 10, 135, 40);
    lbl_co2 = lv_label_create(box_co2);
    lv_obj_set_style_text_font(lbl_co2, FONT_VALUE, 0);
    lv_obj_set_style_text_color(lbl_co2, lv_color_white(), 0);

    lv_obj_t *p_set_t  = create_panel(scr, 8, 224, 228, 88, &style_setpanel);
    lv_obj_t *p_set_rh = create_panel(scr, 244, 224, 228, 88, &style_setpanel);

    lv_obj_t *st = lv_label_create(p_set_t);
    lv_label_set_text(st, "Уставка Т");
    lv_obj_set_style_text_font(st, FONT_TITLE, 0);
    lv_obj_set_style_text_color(st, lv_color_white(), 0);
    lv_obj_set_pos(st, 6, 4);

    create_pm_button(p_set_t, "-", 18, 42, ACT_TEMP_MINUS);
    box_temp_set = create_value_box(p_set_t, 64, 38, 100, 36);
    lbl_temp_set = lv_label_create(box_temp_set);
    lv_obj_set_style_text_font(lbl_temp_set, FONT_VALUE, 0);
    lv_obj_set_style_text_color(lbl_temp_set, lv_color_white(), 0);
    create_pm_button(p_set_t, "+", 174, 42, ACT_TEMP_PLUS);

    lv_obj_t *srh = lv_label_create(p_set_rh);
    lv_label_set_text(srh, "Уставка RH");
    lv_obj_set_style_text_font(srh, FONT_TITLE, 0);
    lv_obj_set_style_text_color(srh, lv_color_white(), 0);
    lv_obj_set_pos(srh, 6, 4);

    create_pm_button(p_set_rh, "-", 18, 42, ACT_HUM_MINUS);
    box_hum_set = create_value_box(p_set_rh, 64, 38, 100, 36);
    lbl_hum_set = lv_label_create(box_hum_set);
    lv_obj_set_style_text_font(lbl_hum_set, FONT_VALUE, 0);
    lv_obj_set_style_text_color(lbl_hum_set, lv_color_white(), 0);
    create_pm_button(p_set_rh, "+", 174, 42, ACT_HUM_PLUS);

    refresh_values();
}

static void schedule_screen_create(void)
{
    screen_schedule = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen_schedule, lv_color_hex(0x08121D), 0);

    lv_obj_t *top = create_panel(screen_schedule, 8, 6, 464, 40, &style_topbar);

    lv_obj_t *btn_prev = lv_button_create(top);
    lv_obj_set_size(btn_prev, 40, 28);
    lv_obj_set_pos(btn_prev, 8, 6);
    lv_obj_add_style(btn_prev, &style_btn, 0);
    lv_obj_add_event_cb(btn_prev, schedule_event_cb, LV_EVENT_CLICKED, (void *)(intptr_t)SCH_DAY_PREV);

    lv_obj_t *lbl_prev = lv_label_create(btn_prev);
    lv_label_set_text(lbl_prev, "<");
    lv_obj_set_style_text_font(lbl_prev, FONT_TITLE, 0);
    lv_obj_set_style_text_color(lbl_prev, lv_color_white(), 0);
    lv_obj_center(lbl_prev);

    lbl_day_name = lv_label_create(top);
    lv_obj_set_style_text_font(lbl_day_name, FONT_BIG, 0);
    lv_obj_set_style_text_color(lbl_day_name, lv_color_hex(0xFFA51E), 0);
    lv_obj_align(lbl_day_name, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t *btn_next = lv_button_create(top);
    lv_obj_set_size(btn_next, 40, 28);
    lv_obj_set_pos(btn_next, 416, 6);
    lv_obj_add_style(btn_next, &style_btn, 0);
    lv_obj_add_event_cb(btn_next, schedule_event_cb, LV_EVENT_CLICKED, (void *)(intptr_t)SCH_DAY_NEXT);

    lv_obj_t *lbl_next = lv_label_create(btn_next);
    lv_label_set_text(lbl_next, ">");
    lv_obj_set_style_text_font(lbl_next, FONT_TITLE, 0);
    lv_obj_set_style_text_color(lbl_next, lv_color_white(), 0);
    lv_obj_center(lbl_next);

    create_time_editor(screen_schedule, 30, 60,  "ВКЛ1",  &lbl_on1,  SCH_ON1_PLUS,  SCH_ON1_MINUS);
create_time_editor(screen_schedule, 30, 112, "ВЫКЛ1", &lbl_off1, SCH_OFF1_PLUS, SCH_OFF1_MINUS);
create_time_editor(screen_schedule, 30, 164, "ВКЛ2",  &lbl_on2,  SCH_ON2_PLUS,  SCH_ON2_MINUS);
create_time_editor(screen_schedule, 30, 216, "ВЫКЛ2", &lbl_off2, SCH_OFF2_PLUS, SCH_OFF2_MINUS);

    lv_obj_t *btn_back = lv_button_create(screen_schedule);
    lv_obj_set_size(btn_back, 120, 34);
    lv_obj_set_pos(btn_back, 180, 282);
    lv_obj_add_style(btn_back, &style_btn, 0);
    lv_obj_add_event_cb(btn_back, schedule_event_cb, LV_EVENT_CLICKED, (void *)(intptr_t)SCH_BACK);

    lv_obj_t *lbl_back = lv_label_create(btn_back);
    lv_label_set_text(lbl_back, "НАЗАД");
    lv_obj_set_style_text_font(lbl_back, FONT_TITLE, 0);
    lv_obj_set_style_text_color(lbl_back, lv_color_white(), 0);
    lv_obj_center(lbl_back);

    refresh_schedule_screen();
}

/* -------- Modbus helpers -------- */
static uint16_t mb_crc16(const uint8_t *data, uint16_t len)
{
    uint16_t crc = 0xFFFF;

    for (uint16_t pos = 0; pos < len; pos++) {
        crc ^= data[pos];
        for (int i = 0; i < 8; i++) {
            if (crc & 0x0001) {
                crc >>= 1;
                crc ^= 0xA001;
            } else {
                crc >>= 1;
            }
        }
    }
    return crc;
}

static uint16_t reg_read_u16(uint16_t reg)
{
    uint16_t value = 0;

    portENTER_CRITICAL(&reg_lock);

    if (reg <= 6) {
        switch (reg) {
            case 0: value = (uint16_t)room_temp; break;
            case 1: value = (uint16_t)room_hum; break;
            case 2: value = (uint16_t)duct_temp; break;
            case 3: value = (uint16_t)co2_ppm; break;
            case 4: value = (uint16_t)temp_setpoint; break;
            case 5: value = (uint16_t)hum_setpoint; break;
            case 6: value = status_flags; break;
            default: value = 0; break;
        }
    } else {
        uint16_t idx = reg - 7;            /* 0..55 */
        uint8_t point_index = idx / 2;     /* 0..27 */
        uint8_t word_index  = idx % 2;     /* 0 high, 1 low */

        uint8_t day   = point_index / 4;   /* 0..6 */
        uint8_t point = point_index % 4;   /* 0..3 */

        uint32_t *p = schedule_point_ptr(day, point);
        if (p) {
            uint32_t v = *p;
            value = (word_index == 0) ? (uint16_t)(v >> 16) : (uint16_t)(v & 0xFFFFU);
        }
    }

    portEXIT_CRITICAL(&reg_lock);
    return value;
}

static bool reg_write_u16(uint16_t reg, uint16_t value)
{
    bool ok = true;

    portENTER_CRITICAL(&reg_lock);

    if (reg <= 6) {
        switch (reg) {
            case 0:
                room_temp = (int16_t)value;
                break;
            case 1:
                room_hum = (int16_t)value;
                break;
            case 2:
                duct_temp = (int16_t)value;
                break;
            case 3:
                co2_ppm = (int16_t)value;
                break;
            case 4:
                temp_setpoint = (int16_t)value;
                if (temp_setpoint < 250) temp_setpoint = 250;
                if (temp_setpoint > 400) temp_setpoint = 400;
                break;
            case 5:
                hum_setpoint = (int16_t)value;
                if (hum_setpoint < 40) hum_setpoint = 40;
                if (hum_setpoint > 60) hum_setpoint = 60;
                break;
            case 6:
                status_flags = value;
                break;
            default:
                ok = false;
                break;
        }
    } else {
        uint16_t idx = reg - 7;           
        uint8_t point_index = idx / 2;    
        uint8_t word_index  = idx % 2;    

        uint8_t day   = point_index / 4;
        uint8_t point = point_index % 4;

        uint32_t *p = schedule_point_ptr(day, point);
        if (p) {
            uint32_t v = *p;
            if (word_index == 0) {
                v = (v & 0x0000FFFFUL) | ((uint32_t)value << 16);
            } else {
                v = (v & 0xFFFF0000UL) | (uint32_t)value;
            }

            if (v >= DAY_SEC) {
                v = 0;
            }

            *p = v;
        } else {
            ok = false;
        }
    }

    portEXIT_CRITICAL(&reg_lock);
    return ok;
}

static int mb_build_exception(uint8_t addr, uint8_t func, uint8_t excode, uint8_t *tx)
{
    tx[0] = addr;
    tx[1] = func | 0x80;
    tx[2] = excode;

    uint16_t crc = mb_crc16(tx, 3);
    tx[3] = crc & 0xFF;
    tx[4] = (crc >> 8) & 0xFF;

    return 5;
}

static int mb_handle_read_holding(const uint8_t *rx, int rx_len, uint8_t *tx)
{
    if (rx_len < 8) {
        return 0;
    }

    uint16_t start_reg = ((uint16_t)rx[2] << 8) | rx[3];
    uint16_t reg_count = ((uint16_t)rx[4] << 8) | rx[5];

    if (reg_count == 0 || reg_count > 125) {
        return mb_build_exception(rx[0], rx[1], 0x03, tx);
    }

    if ((start_reg + reg_count) > MB_REG_COUNT) {
        return mb_build_exception(rx[0], rx[1], 0x02, tx);
    }

    tx[0] = rx[0];
    tx[1] = rx[1];
    tx[2] = reg_count * 2;

    int idx = 3;
    for (uint16_t i = 0; i < reg_count; i++) {
        uint16_t value = reg_read_u16(start_reg + i);
        tx[idx++] = (value >> 8) & 0xFF;
        tx[idx++] = value & 0xFF;
    }

    uint16_t crc = mb_crc16(tx, idx);
    tx[idx++] = crc & 0xFF;
    tx[idx++] = (crc >> 8) & 0xFF;

    return idx;
}

static int mb_handle_write_single(const uint8_t *rx, int rx_len, uint8_t *tx)
{
    if (rx_len < 8) {
        return 0;
    }

    uint16_t reg = ((uint16_t)rx[2] << 8) | rx[3];
    uint16_t value = ((uint16_t)rx[4] << 8) | rx[5];

    if (reg >= MB_REG_COUNT) {
        return mb_build_exception(rx[0], rx[1], 0x02, tx);
    }

    if (!reg_write_u16(reg, value)) {
        return mb_build_exception(rx[0], rx[1], 0x03, tx);
    }

    memcpy(tx, rx, 6);

    uint16_t crc = mb_crc16(tx, 6);
    tx[6] = crc & 0xFF;
    tx[7] = (crc >> 8) & 0xFF;

    return 8;
}

static int mb_handle_write_multiple(const uint8_t *rx, int rx_len, uint8_t *tx)
{
    if (rx_len < 9) {
        return 0;
    }

    uint16_t start_reg = ((uint16_t)rx[2] << 8) | rx[3];
    uint16_t reg_count = ((uint16_t)rx[4] << 8) | rx[5];
    uint8_t byte_count = rx[6];

    if (reg_count == 0 || reg_count > 123) {
        return mb_build_exception(rx[0], rx[1], 0x03, tx);
    }

    if ((start_reg + reg_count) > MB_REG_COUNT) {
        return mb_build_exception(rx[0], rx[1], 0x02, tx);
    }

    if (byte_count != reg_count * 2) {
        return mb_build_exception(rx[0], rx[1], 0x03, tx);
    }

    if (rx_len < (9 + byte_count - 2)) {
        return 0;
    }

    for (uint16_t i = 0; i < reg_count; i++) {
        uint16_t value = ((uint16_t)rx[7 + i * 2] << 8) | rx[8 + i * 2];
        if (!reg_write_u16(start_reg + i, value)) {
            return mb_build_exception(rx[0], rx[1], 0x03, tx);
        }
    }

    tx[0] = rx[0];
    tx[1] = rx[1];
    tx[2] = rx[2];
    tx[3] = rx[3];
    tx[4] = rx[4];
    tx[5] = rx[5];

    uint16_t crc = mb_crc16(tx, 6);
    tx[6] = crc & 0xFF;
    tx[7] = (crc >> 8) & 0xFF;

    return 8;
}

static void modbus_slave_task(void *arg)
{
    (void)arg;

    uint8_t rx_buf[MB_RX_BUF_SIZE];
    uint8_t tx_buf[MB_TX_BUF_SIZE];

    while (1) {
        int len = uart_read_bytes(MB_UART_NUM, rx_buf, sizeof(rx_buf), pdMS_TO_TICKS(100));
        if (len < 8) {
            continue;
        }

        uint16_t crc_rx = ((uint16_t)rx_buf[len - 1] << 8) | rx_buf[len - 2];
        uint16_t crc_calc = mb_crc16(rx_buf, len - 2);

        if (crc_rx != crc_calc) {
            continue;
        }

        if (rx_buf[0] != MB_SLAVE_ADDR) {
            continue;
        }

        int tx_len = 0;

        switch (rx_buf[1]) {
            case 0x03:
                tx_len = mb_handle_read_holding(rx_buf, len, tx_buf);
                break;

            case 0x06:
                tx_len = mb_handle_write_single(rx_buf, len, tx_buf);
                break;

            case 0x10:
                tx_len = mb_handle_write_multiple(rx_buf, len, tx_buf);
                break;

            default:
                tx_len = mb_build_exception(rx_buf[0], rx_buf[1], 0x01, tx_buf);
                break;
        }

        if (tx_len > 0) {
            uart_write_bytes(MB_UART_NUM, (const char *)tx_buf, tx_len);
            uart_wait_tx_done(MB_UART_NUM, pdMS_TO_TICKS(100));
        }

        lvgl_port_lock(0);
        refresh_values();
        refresh_schedule_screen();
        lvgl_port_unlock();
    }
}

static void modbus_init(void)
{
    const uart_config_t uart_config = {
        .baud_rate = MB_BAUD_RATE,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_DEFAULT,
    };

    ESP_ERROR_CHECK(uart_driver_install(MB_UART_NUM, MB_RX_BUF_SIZE, MB_TX_BUF_SIZE, 0, NULL, 0));
    ESP_ERROR_CHECK(uart_param_config(MB_UART_NUM, &uart_config));
    ESP_ERROR_CHECK(uart_set_pin(MB_UART_NUM, MB_TXD_PIN, MB_RXD_PIN, MB_RTS_PIN, UART_PIN_NO_CHANGE));
    ESP_ERROR_CHECK(uart_set_mode(MB_UART_NUM, UART_MODE_RS485_HALF_DUPLEX));

    xTaskCreate(modbus_slave_task, "modbus_slave_task", 4096, NULL, 5, NULL);

    ESP_LOGI(TAG, "Modbus RTU slave started: addr=%d baud=%d regs=%d",
             MB_SLAVE_ADDR, MB_BAUD_RATE, MB_REG_COUNT);
}

/* -------- app main -------- */
void app_main(void)
{
    board_backlight_on();
    board_shared_reset_pulse();

    lcd_init();
    touch_init();

    ESP_LOGI(TAG, "lcd_io_handle=%p panel_handle=%p tp=%p", lcd_io_handle, panel_handle, tp);

    const lvgl_port_cfg_t lvgl_cfg = ESP_LVGL_PORT_INIT_CONFIG();
    ESP_ERROR_CHECK(lvgl_port_init(&lvgl_cfg));

    const lvgl_port_display_cfg_t disp_cfg = {
        .io_handle = lcd_io_handle,
        .panel_handle = panel_handle,
        .buffer_size = LCD_H_RES * LCD_DRAW_BUF_LINES,
        .double_buffer = false,
        .hres = LCD_H_RES,
        .vres = LCD_V_RES,
        .monochrome = false,
        .color_format = LV_COLOR_FORMAT_RGB565,
        .rotation = {
            .swap_xy = true,
            .mirror_x = false,
            .mirror_y = false,
        },
        .flags = {
            .buff_dma = false,
            .swap_bytes = false,
        }
    };

    disp = lvgl_port_add_disp(&disp_cfg);
    assert(disp != NULL);

    const lvgl_port_touch_cfg_t touch_cfg = {
        .disp = disp,
        .handle = tp,
    };

    touch_indev = lvgl_port_add_touch(&touch_cfg);
    assert(touch_indev != NULL);

    lvgl_port_lock(0);
    ui_create();
    screen_main = lv_screen_active();
    schedule_screen_create();
    lvgl_port_unlock();

    modbus_init();

    ESP_LOGI(TAG, "Climate UI + Schedule ready");

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
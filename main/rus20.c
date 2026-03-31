/*******************************************************************************
 * Size: 20 px
 * Bpp: 1
 * Opts: --bpp 1 --size 20 --no-compress --stride 1 --align 1 --font ofont.ru_Nunito.ttf --range 32-126,176,1025,1040-1103,1105 --format lvgl -o rus20.c
 ******************************************************************************/

#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif



#ifndef RUS20
#define RUS20 1
#endif

#if RUS20

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0x6f, 0xf6, 0x66, 0x66, 0x66, 0x7, 0x77,

    /* U+0022 "\"" */
    0xcf, 0xdf, 0xbf, 0x7c, 0x68, 0x80,

    /* U+0023 "#" */
    0x18, 0x86, 0x61, 0x9b, 0xff, 0xff, 0xcc, 0x43,
    0x30, 0xcc, 0x23, 0x3f, 0xff, 0xfd, 0x98, 0x66,
    0x11, 0x80,

    /* U+0024 "$" */
    0xc, 0x1, 0x80, 0x7c, 0x3f, 0xef, 0x1d, 0xc0,
    0x38, 0x7, 0x80, 0x7f, 0x7, 0xf8, 0xf, 0x80,
    0x70, 0xf, 0x83, 0xff, 0xf3, 0xf8, 0xc, 0x1,
    0x80, 0x0, 0x0,

    /* U+0025 "%" */
    0x0, 0x0, 0x1c, 0xc, 0x1f, 0xe, 0x18, 0xc6,
    0xc, 0x67, 0x6, 0x33, 0x3, 0x1b, 0x38, 0xf9,
    0xbe, 0x39, 0xbb, 0x81, 0xd8, 0xc0, 0xcc, 0x60,
    0xe6, 0x30, 0x63, 0xb8, 0x60, 0xf8, 0x30, 0x38,

    /* U+0026 "&" */
    0x1f, 0x3, 0xfc, 0x1c, 0x60, 0xe3, 0x3, 0xb0,
    0xf, 0x18, 0xf8, 0xce, 0xe6, 0xe3, 0xe7, 0xf,
    0x38, 0x39, 0xe3, 0xc7, 0xff, 0x1f, 0x18,

    /* U+0027 "'" */
    0xdf, 0xfc, 0x80,

    /* U+0028 "(" */
    0x31, 0x9c, 0xe6, 0x73, 0x9c, 0xe7, 0x39, 0xce,
    0x39, 0xc6, 0x30, 0x80,

    /* U+0029 ")" */
    0xe3, 0x1c, 0xe3, 0x1c, 0xe7, 0x39, 0xce, 0x73,
    0xb9, 0xcc, 0xe2, 0x0,

    /* U+002A "*" */
    0x24, 0x3c, 0x3c, 0xff, 0xff, 0x3c, 0x3c, 0x24,

    /* U+002B "+" */
    0xc, 0x3, 0x0, 0xc0, 0x30, 0xff, 0xff, 0xf0,
    0xc0, 0x30, 0xc, 0x3, 0x0,

    /* U+002C "," */
    0xff, 0xb4,

    /* U+002D "-" */
    0xff, 0xf0,

    /* U+002E "." */
    0xff, 0x80,

    /* U+002F "/" */
    0x4, 0x18, 0x30, 0x61, 0x83, 0x6, 0x18, 0x30,
    0x61, 0x83, 0x6, 0x18, 0x30, 0x60,

    /* U+0030 "0" */
    0x1f, 0x7, 0xf1, 0xc7, 0x70, 0x6e, 0xf, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xfc, 0x1f, 0x87, 0x38,
    0xe3, 0xf8, 0x3e, 0x0,

    /* U+0031 "1" */
    0x1c, 0x1e, 0x3f, 0x1b, 0x81, 0xc0, 0xe0, 0x70,
    0x38, 0x1c, 0xe, 0x7, 0x3, 0x8f, 0xff, 0xfc,

    /* U+0032 "2" */
    0x3f, 0x1f, 0xf3, 0xf, 0x0, 0xe0, 0x1c, 0x3,
    0x80, 0xe0, 0x3c, 0xf, 0x3, 0xc0, 0x70, 0x1c,
    0x7, 0xfe, 0xff, 0xc0,

    /* U+0033 "3" */
    0x1f, 0x8f, 0xf9, 0x87, 0x80, 0x70, 0xe, 0x3,
    0x83, 0xe0, 0x7e, 0x1, 0xe0, 0x1c, 0x3, 0xb0,
    0xf7, 0xfc, 0x7e, 0x0,

    /* U+0034 "4" */
    0x1, 0x80, 0x70, 0x1e, 0x7, 0xc0, 0xf8, 0x37,
    0xc, 0xe3, 0x9c, 0x63, 0x9f, 0xff, 0xff, 0x81,
    0xc0, 0x38, 0x7, 0x0,

    /* U+0035 "5" */
    0xff, 0xbf, 0xee, 0x3, 0x80, 0xe0, 0x3f, 0xcf,
    0xfb, 0x8f, 0x1, 0xc0, 0x70, 0x1f, 0xe, 0xff,
    0x9f, 0x80,

    /* U+0036 "6" */
    0xf, 0x87, 0xfd, 0xe1, 0x38, 0xe, 0x1, 0xde,
    0x3f, 0xe7, 0x9e, 0xf1, 0xdc, 0x3b, 0xc7, 0x39,
    0xe3, 0xf8, 0x3e, 0x0,

    /* U+0037 "7" */
    0xff, 0xff, 0xf0, 0x1c, 0xe, 0x3, 0x81, 0xc0,
    0x60, 0x38, 0xc, 0x7, 0x3, 0x80, 0xe0, 0x70,
    0x1c, 0x0,

    /* U+0038 "8" */
    0x3f, 0xf, 0xf3, 0xcf, 0x70, 0xee, 0x1c, 0xe7,
    0x8f, 0xe1, 0xfc, 0xf1, 0xdc, 0x1f, 0x83, 0xf8,
    0xf7, 0xfc, 0x7f, 0x0,

    /* U+0039 "9" */
    0x1f, 0x7, 0xf1, 0xe7, 0x38, 0xf7, 0xe, 0xe3,
    0xde, 0x79, 0xff, 0x1e, 0xe0, 0x1c, 0x7, 0x21,
    0xe7, 0xf8, 0x7c, 0x0,

    /* U+003A ":" */
    0xff, 0x80, 0x7, 0xfc,

    /* U+003B ";" */
    0xff, 0x80, 0x7, 0xfd, 0xa0,

    /* U+003C "<" */
    0x0, 0x40, 0x70, 0xf8, 0xf0, 0xf0, 0x38, 0x7,
    0x80, 0x7c, 0x7, 0xc0, 0x30,

    /* U+003D "=" */
    0xff, 0xff, 0xf0, 0x0, 0x0, 0xff, 0xff, 0xf0,

    /* U+003E ">" */
    0x80, 0x38, 0x7, 0xc0, 0x7c, 0x3, 0xc0, 0x70,
    0x78, 0xf8, 0xf0, 0x30, 0x0,

    /* U+003F "?" */
    0x3e, 0x7f, 0xb0, 0xe0, 0x70, 0x38, 0x38, 0x38,
    0x18, 0xc, 0x4, 0x0, 0x3, 0x81, 0xc0, 0xe0,

    /* U+0040 "@" */
    0x3, 0xf0, 0x7, 0xfe, 0x7, 0x3, 0x86, 0x0,
    0xe6, 0x3d, 0xb3, 0x3f, 0xcf, 0x18, 0xc7, 0x98,
    0x63, 0xcc, 0x31, 0xe6, 0x18, 0xf3, 0xc, 0x79,
    0xce, 0x66, 0x7f, 0xf3, 0x1c, 0xf0, 0xc0, 0x0,
    0x38, 0x18, 0xf, 0xfc, 0x1, 0xf8, 0x0,

    /* U+0041 "A" */
    0x3, 0x80, 0x7, 0x0, 0x1f, 0x0, 0x36, 0x0,
    0xee, 0x1, 0x8c, 0x7, 0x18, 0xe, 0x38, 0x18,
    0x30, 0x7f, 0xf0, 0xff, 0xe3, 0x80, 0xe6, 0x0,
    0xcc, 0x1, 0x80,

    /* U+0042 "B" */
    0xff, 0x9f, 0xfb, 0x87, 0xf0, 0x7e, 0xf, 0xc3,
    0xbf, 0xe7, 0xfe, 0xe1, 0xfc, 0x1f, 0x83, 0xf0,
    0xff, 0xfd, 0xff, 0x0,

    /* U+0043 "C" */
    0xf, 0xc3, 0xff, 0x78, 0x37, 0x0, 0xe0, 0xe,
    0x0, 0xe0, 0xe, 0x0, 0xe0, 0xe, 0x0, 0x70,
    0x7, 0x83, 0x3f, 0xf0, 0xfc,

    /* U+0044 "D" */
    0xff, 0x87, 0xff, 0x38, 0x3d, 0xc0, 0xee, 0x3,
    0xf0, 0x1f, 0x80, 0xfc, 0x7, 0xe0, 0x3f, 0x1,
    0xf8, 0x1d, 0xc1, 0xef, 0xfe, 0x7f, 0xc0,

    /* U+0045 "E" */
    0xff, 0xbf, 0xee, 0x3, 0x80, 0xe0, 0x38, 0xf,
    0xfb, 0xfe, 0xe0, 0x38, 0xe, 0x3, 0x80, 0xff,
    0xbf, 0xe0,

    /* U+0046 "F" */
    0xff, 0xbf, 0xee, 0x3, 0x80, 0xe0, 0x38, 0xf,
    0xfb, 0xfe, 0xe0, 0x38, 0xe, 0x3, 0x80, 0xe0,
    0x38, 0x0,

    /* U+0047 "G" */
    0xf, 0xe0, 0xff, 0x8e, 0xc, 0xe0, 0xe, 0x0,
    0x70, 0x3, 0x87, 0xdc, 0x3e, 0xe0, 0x37, 0x1,
    0x9c, 0xc, 0xf0, 0x63, 0xff, 0x7, 0xf0,

    /* U+0048 "H" */
    0xe0, 0x3f, 0x1, 0xf8, 0xf, 0xc0, 0x7e, 0x3,
    0xf0, 0x1f, 0xff, 0xff, 0xff, 0xe0, 0x3f, 0x1,
    0xf8, 0xf, 0xc0, 0x7e, 0x3, 0xf0, 0x1c,

    /* U+0049 "I" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,

    /* U+004A "J" */
    0xe, 0x1c, 0x38, 0x70, 0xe1, 0xc3, 0x87, 0xe,
    0x1c, 0x38, 0x77, 0xcf, 0x0,

    /* U+004B "K" */
    0xe0, 0x6e, 0xe, 0xe1, 0xce, 0x38, 0xe7, 0xe,
    0xe0, 0xfc, 0xf, 0xc0, 0xee, 0xe, 0x70, 0xe3,
    0x8e, 0x1c, 0xe0, 0xee, 0x6,

    /* U+004C "L" */
    0xe0, 0x38, 0xe, 0x3, 0x80, 0xe0, 0x38, 0xe,
    0x3, 0x80, 0xe0, 0x38, 0xe, 0x3, 0x80, 0xff,
    0xbf, 0xe0,

    /* U+004D "M" */
    0xc0, 0x7, 0xc0, 0x1f, 0xc0, 0x7f, 0x80, 0xff,
    0x83, 0xff, 0x7, 0xfb, 0x1b, 0xf3, 0x67, 0xe6,
    0xcf, 0xc7, 0x1f, 0x8e, 0x3f, 0x8, 0x7e, 0x0,
    0xfc, 0x1, 0xc0,

    /* U+004E "N" */
    0xc0, 0x7e, 0x7, 0xf0, 0x7f, 0x7, 0xf8, 0x7e,
    0xc7, 0xe6, 0x7e, 0x67, 0xe3, 0x7e, 0x1f, 0xe0,
    0xfe, 0xf, 0xe0, 0x7e, 0x3,

    /* U+004F "O" */
    0xf, 0xc0, 0xff, 0xc7, 0x87, 0x9c, 0xe, 0xe0,
    0x1f, 0x80, 0x7e, 0x1, 0xf8, 0x7, 0xe0, 0x1f,
    0x80, 0x77, 0x3, 0x9e, 0x1e, 0x3f, 0xf0, 0x3f,
    0x0,

    /* U+0050 "P" */
    0xff, 0x9f, 0xfb, 0x87, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x7f, 0xfe, 0xff, 0x9c, 0x3, 0x80, 0x70,
    0xe, 0x1, 0xc0, 0x0,

    /* U+0051 "Q" */
    0xf, 0xc0, 0xff, 0xc7, 0x87, 0x9c, 0xe, 0xe0,
    0x1f, 0x80, 0x7e, 0x1, 0xf8, 0x7, 0xe0, 0x1f,
    0x80, 0x77, 0x3, 0x9e, 0x1e, 0x3f, 0xf0, 0x3f,
    0x0, 0xe, 0x0, 0x1c, 0x0, 0x38, 0x0, 0xc0,

    /* U+0052 "R" */
    0xff, 0x9f, 0xfb, 0x87, 0xf0, 0x7e, 0xf, 0xc3,
    0xff, 0xf7, 0xf8, 0xe3, 0x9c, 0x33, 0x87, 0x70,
    0xee, 0xf, 0xc0, 0xc0,

    /* U+0053 "S" */
    0xf, 0xc3, 0xff, 0x78, 0x77, 0x0, 0x70, 0x7,
    0x80, 0x3f, 0x81, 0xfe, 0x1, 0xf0, 0x7, 0x0,
    0x76, 0xf, 0x7f, 0xe3, 0xf8,

    /* U+0054 "T" */
    0xff, 0xff, 0xff, 0xc1, 0xc0, 0xe, 0x0, 0x70,
    0x3, 0x80, 0x1c, 0x0, 0xe0, 0x7, 0x0, 0x38,
    0x1, 0xc0, 0xe, 0x0, 0x70, 0x3, 0x80,

    /* U+0055 "U" */
    0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e,
    0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0,
    0x77, 0xe, 0x3f, 0xe1, 0xf8,

    /* U+0056 "V" */
    0xe0, 0xf, 0x80, 0x77, 0x1, 0x9c, 0xe, 0x30,
    0x38, 0xe1, 0xc1, 0x87, 0x7, 0x18, 0xc, 0xe0,
    0x3b, 0x0, 0x7c, 0x1, 0xe0, 0x7, 0x80, 0xc,
    0x0,

    /* U+0057 "W" */
    0xc0, 0x60, 0x37, 0x3, 0x81, 0xb8, 0x3c, 0xc,
    0xc1, 0xe0, 0xe7, 0xf, 0x86, 0x38, 0xec, 0x70,
    0xc6, 0x63, 0x87, 0x33, 0x98, 0x3b, 0x8d, 0xc0,
    0xd8, 0x6c, 0x7, 0xc1, 0xe0, 0x1c, 0xf, 0x0,
    0xe0, 0x70, 0x7, 0x1, 0x80,

    /* U+0058 "X" */
    0xc0, 0x6e, 0xe, 0x70, 0xe3, 0x9c, 0x3b, 0x81,
    0xf0, 0xe, 0x0, 0xf0, 0x1f, 0x3, 0xb8, 0x71,
    0xc7, 0xe, 0xe0, 0x6c, 0x6,

    /* U+0059 "Y" */
    0x60, 0x33, 0x81, 0x9c, 0x1c, 0x71, 0xc1, 0xdc,
    0xf, 0xe0, 0x3e, 0x0, 0xe0, 0x7, 0x0, 0x38,
    0x1, 0xc0, 0xe, 0x0, 0x70, 0x3, 0x80,

    /* U+005A "Z" */
    0xff, 0xdf, 0xfc, 0x7, 0x1, 0xc0, 0x38, 0xe,
    0x3, 0x80, 0x60, 0x1c, 0x7, 0x1, 0xc0, 0x38,
    0xf, 0xff, 0xff, 0xc0,

    /* U+005B "[" */
    0xff, 0xf9, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce,
    0x73, 0x9c, 0xff, 0xc0,

    /* U+005C "\\" */
    0xc1, 0x83, 0x3, 0x6, 0xc, 0xc, 0x18, 0x30,
    0x30, 0x60, 0xc0, 0xc1, 0x83, 0x6,

    /* U+005D "]" */
    0xff, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xce, 0x73,
    0x9c, 0xe7, 0xff, 0xc0,

    /* U+005E "^" */
    0xc, 0x7, 0x81, 0xe0, 0x78, 0x33, 0xc, 0xc6,
    0x19, 0x86, 0xc0, 0xf0, 0x30,

    /* U+005F "_" */
    0xff, 0xff, 0xf0,

    /* U+0060 "`" */
    0xc, 0x66, 0x20,

    /* U+0061 "a" */
    0x7e, 0x7f, 0xb0, 0xe0, 0x73, 0xff, 0xff, 0x8f,
    0xc7, 0xff, 0xbd, 0xc0,

    /* U+0062 "b" */
    0xe0, 0x38, 0xe, 0x3, 0x80, 0xef, 0x3f, 0xef,
    0x3f, 0x87, 0xe1, 0xf8, 0x7e, 0x1f, 0xcf, 0xff,
    0xbb, 0xc0,

    /* U+0063 "c" */
    0x1f, 0x3f, 0xdc, 0x5c, 0xe, 0x7, 0x3, 0x80,
    0xe2, 0x7f, 0x8f, 0x80,

    /* U+0064 "d" */
    0x1, 0xc0, 0x70, 0x1c, 0x7, 0x3d, 0xdf, 0xff,
    0x3f, 0x87, 0xe1, 0xf8, 0x7e, 0x1f, 0xcf, 0x7f,
    0xcf, 0x70,

    /* U+0065 "e" */
    0x1f, 0xf, 0xe7, 0x19, 0x83, 0xff, 0xdf, 0xf6,
    0x1, 0xc3, 0x3f, 0xc7, 0xc0,

    /* U+0066 "f" */
    0x1f, 0x1e, 0x38, 0x38, 0xfe, 0xfe, 0x38, 0x38,
    0x38, 0x38, 0x38, 0x38, 0x38, 0x38,

    /* U+0067 "g" */
    0x3d, 0xdf, 0xff, 0x3f, 0x87, 0xe1, 0xf8, 0x7e,
    0x1f, 0xcf, 0x7f, 0xcf, 0x70, 0x1f, 0xe, 0xff,
    0x9f, 0x80,

    /* U+0068 "h" */
    0xe0, 0x70, 0x38, 0x1c, 0xe, 0xf7, 0xff, 0xcf,
    0xc7, 0xe3, 0xf1, 0xf8, 0xfc, 0x7e, 0x3f, 0x1c,

    /* U+0069 "i" */
    0xfc, 0xf, 0xff, 0xff, 0xff, 0xc0,

    /* U+006A "j" */
    0x1c, 0x70, 0x0, 0x1c, 0x71, 0xc7, 0x1c, 0x71,
    0xc7, 0x1c, 0x71, 0xcf, 0x79, 0x80,

    /* U+006B "k" */
    0xe0, 0x70, 0x38, 0x1c, 0xe, 0x1f, 0x1f, 0x9d,
    0xdc, 0xfc, 0x7e, 0x3b, 0x9c, 0xee, 0x3f, 0xc,

    /* U+006C "l" */
    0xe7, 0x39, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xcf,
    0xbc,

    /* U+006D "m" */
    0xef, 0x3d, 0xfe, 0xff, 0xcf, 0x3f, 0x1c, 0x7e,
    0x38, 0xfc, 0x71, 0xf8, 0xe3, 0xf1, 0xc7, 0xe3,
    0x8f, 0xc7, 0x1c,

    /* U+006E "n" */
    0xef, 0x7f, 0xfc, 0xfc, 0x7e, 0x3f, 0x1f, 0x8f,
    0xc7, 0xe3, 0xf1, 0xc0,

    /* U+006F "o" */
    0x1e, 0x1f, 0xe7, 0x3b, 0x87, 0xe1, 0xf8, 0x7e,
    0x1d, 0xce, 0x7f, 0x87, 0x80,

    /* U+0070 "p" */
    0xef, 0x3f, 0xef, 0x3f, 0x87, 0xe1, 0xf8, 0x7e,
    0x1f, 0xcf, 0xff, 0xbb, 0xce, 0x3, 0x80, 0xe0,
    0x38, 0x0,

    /* U+0071 "q" */
    0x3d, 0xdf, 0xff, 0x3f, 0x87, 0xe1, 0xf8, 0x7e,
    0x1f, 0xcf, 0x7f, 0xcf, 0x70, 0x1c, 0x7, 0x1,
    0xc0, 0x70,

    /* U+0072 "r" */
    0xef, 0xff, 0xc7, 0xe, 0x1c, 0x38, 0x70, 0xe1,
    0xc0,

    /* U+0073 "s" */
    0x1f, 0xf, 0xe7, 0x9, 0xc0, 0x7c, 0x7, 0xc0,
    0x3b, 0xe, 0xff, 0x1f, 0x80,

    /* U+0074 "t" */
    0x38, 0x38, 0x38, 0xff, 0xff, 0x38, 0x38, 0x38,
    0x38, 0x38, 0x38, 0x1f, 0xf,

    /* U+0075 "u" */
    0xe3, 0xf1, 0xf8, 0xfc, 0x7e, 0x3f, 0x1f, 0x8f,
    0xcf, 0xff, 0xbd, 0xc0,

    /* U+0076 "v" */
    0x60, 0xd8, 0x37, 0x1d, 0xc6, 0x33, 0x8e, 0xc1,
    0xf0, 0x78, 0xe, 0x3, 0x0,

    /* U+0077 "w" */
    0x60, 0xc3, 0x30, 0xe1, 0x9c, 0x70, 0xce, 0x7c,
    0xe3, 0x36, 0x61, 0xdb, 0x30, 0x78, 0xf0, 0x3c,
    0x78, 0x1e, 0x3c, 0x6, 0xc, 0x0,

    /* U+0078 "x" */
    0xc1, 0xf1, 0xdd, 0xc7, 0xc1, 0xc0, 0xf0, 0xf8,
    0xee, 0xe3, 0xe0, 0xc0,

    /* U+0079 "y" */
    0x60, 0xd8, 0x37, 0x1d, 0xc6, 0x33, 0x8e, 0xc1,
    0xb0, 0x78, 0x1e, 0x3, 0x80, 0xc0, 0x70, 0x18,
    0x6, 0x0,

    /* U+007A "z" */
    0xff, 0x7f, 0x81, 0x81, 0x81, 0xc1, 0xc0, 0xc0,
    0xc0, 0xff, 0x7f, 0x80,

    /* U+007B "{" */
    0x1e, 0x7c, 0xe1, 0xc3, 0x87, 0xe, 0x1c, 0xf1,
    0xe0, 0xe1, 0xc3, 0x87, 0xe, 0x1c, 0x3e, 0x3c,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,

    /* U+007D "}" */
    0xf1, 0xf0, 0xe1, 0xc3, 0x87, 0xe, 0x1c, 0x1c,
    0x38, 0xe1, 0xc3, 0x87, 0xe, 0x1c, 0xf9, 0xe0,

    /* U+007E "~" */
    0x78, 0xdf, 0xec, 0x78,

    /* U+00B0 "°" */
    0x7b, 0xfc, 0xf3, 0xfd, 0xe0,

    /* U+0401 "Ё" */
    0x3f, 0xf, 0xc0, 0x0, 0x0, 0xff, 0xbf, 0xee,
    0x3, 0x80, 0xe0, 0x38, 0xf, 0xfb, 0xfe, 0xe0,
    0x38, 0xe, 0x3, 0x80, 0xff, 0xbf, 0xe0,

    /* U+0410 "А" */
    0x3, 0x80, 0x7, 0x0, 0x1f, 0x0, 0x36, 0x0,
    0xee, 0x1, 0x8c, 0x7, 0x18, 0xe, 0x38, 0x18,
    0x30, 0x7f, 0xf0, 0xff, 0xe3, 0x80, 0xe6, 0x0,
    0xcc, 0x1, 0x80,

    /* U+0411 "Б" */
    0xff, 0x9f, 0xf3, 0x80, 0x70, 0xe, 0x1, 0xc0,
    0x3f, 0xe7, 0xfe, 0xe1, 0xfc, 0x1f, 0x83, 0xf0,
    0xff, 0xfd, 0xff, 0x0,

    /* U+0412 "В" */
    0xff, 0x9f, 0xfb, 0x87, 0xf0, 0x7e, 0xf, 0xc3,
    0xbf, 0xe7, 0xfe, 0xe1, 0xfc, 0x1f, 0x83, 0xf0,
    0xff, 0xfd, 0xff, 0x0,

    /* U+0413 "Г" */
    0xff, 0xbf, 0xee, 0x3, 0x80, 0xe0, 0x38, 0xe,
    0x3, 0x80, 0xe0, 0x38, 0xe, 0x3, 0x80, 0xe0,
    0x38, 0x0,

    /* U+0414 "Д" */
    0x1f, 0xf8, 0x1f, 0xf8, 0x1c, 0x38, 0x1c, 0x38,
    0x1c, 0x38, 0x1c, 0x38, 0x1c, 0x38, 0x1c, 0x38,
    0x1c, 0x38, 0x18, 0x38, 0x38, 0x38, 0x30, 0x38,
    0xff, 0xff, 0xff, 0xff, 0xe0, 0x7, 0xe0, 0x7,
    0xe0, 0x7, 0xe0, 0x7,

    /* U+0415 "Е" */
    0xff, 0xbf, 0xee, 0x3, 0x80, 0xe0, 0x38, 0xf,
    0xfb, 0xfe, 0xe0, 0x38, 0xe, 0x3, 0x80, 0xff,
    0xbf, 0xe0,

    /* U+0416 "Ж" */
    0x60, 0xe0, 0xce, 0x1c, 0x38, 0xc3, 0x86, 0x1c,
    0x71, 0xc1, 0xce, 0x70, 0x39, 0xce, 0x3, 0xff,
    0x80, 0xff, 0xf8, 0x38, 0xe3, 0x8e, 0x1c, 0x39,
    0xc3, 0x87, 0x70, 0x70, 0x7e, 0xe, 0xf, 0x81,
    0xc0, 0xc0,

    /* U+0417 "З" */
    0x1f, 0x87, 0xfe, 0x70, 0xf0, 0x7, 0x0, 0x70,
    0xe, 0x1f, 0xc1, 0xfe, 0x0, 0xf0, 0x7, 0x0,
    0x76, 0xf, 0x7f, 0xe3, 0xf8,

    /* U+0418 "И" */
    0xe0, 0x3e, 0x7, 0xe0, 0xfe, 0xf, 0xe1, 0xfe,
    0x37, 0xe6, 0x7e, 0x67, 0xec, 0x7f, 0x87, 0xf0,
    0x7f, 0x7, 0xe0, 0x7c, 0x7,

    /* U+0419 "Й" */
    0x20, 0x83, 0x18, 0x3f, 0x0, 0xe0, 0x0, 0xe,
    0x3, 0xe0, 0x7e, 0xf, 0xe0, 0xfe, 0x1f, 0xe3,
    0x7e, 0x67, 0xe6, 0x7e, 0xc7, 0xf8, 0x7f, 0x7,
    0xf0, 0x7e, 0x7, 0xc0, 0x70,

    /* U+041A "К" */
    0xe0, 0xee, 0xe, 0xe1, 0xce, 0x18, 0xe3, 0x8e,
    0x70, 0xff, 0xf, 0xf8, 0xe1, 0xce, 0x1c, 0xe0,
    0xee, 0xe, 0xe0, 0x7e, 0x7,

    /* U+041B "Л" */
    0x1f, 0xf8, 0xff, 0xc7, 0xe, 0x38, 0x71, 0xc3,
    0x8e, 0x1c, 0x70, 0xe3, 0x87, 0x1c, 0x39, 0xc1,
    0xce, 0xe, 0xe0, 0x7e, 0x3, 0xe0, 0x1c,

    /* U+041C "М" */
    0xc0, 0x7, 0xc0, 0x1f, 0xc0, 0x7f, 0x80, 0xff,
    0x83, 0xff, 0x7, 0xfb, 0x1b, 0xf3, 0x67, 0xe6,
    0xcf, 0xc7, 0x1f, 0x8e, 0x3f, 0x8, 0x7e, 0x0,
    0xfc, 0x1, 0xc0,

    /* U+041D "Н" */
    0xe0, 0x3f, 0x1, 0xf8, 0xf, 0xc0, 0x7e, 0x3,
    0xf0, 0x1f, 0xff, 0xff, 0xff, 0xe0, 0x3f, 0x1,
    0xf8, 0xf, 0xc0, 0x7e, 0x3, 0xf0, 0x1c,

    /* U+041E "О" */
    0xf, 0xc0, 0xff, 0xc7, 0x87, 0x9c, 0xe, 0xe0,
    0x1f, 0x80, 0x7e, 0x1, 0xf8, 0x7, 0xe0, 0x1f,
    0x80, 0x77, 0x3, 0x9e, 0x1e, 0x3f, 0xf0, 0x3f,
    0x0,

    /* U+041F "П" */
    0xff, 0xff, 0xff, 0xe0, 0x7e, 0x7, 0xe0, 0x7e,
    0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0,
    0x7e, 0x7, 0xe0, 0x7e, 0x7,

    /* U+0420 "Р" */
    0xff, 0x9f, 0xfb, 0x87, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x7f, 0xfe, 0xff, 0x9c, 0x3, 0x80, 0x70,
    0xe, 0x1, 0xc0, 0x0,

    /* U+0421 "С" */
    0xf, 0xc3, 0xff, 0x78, 0x37, 0x0, 0xe0, 0xe,
    0x0, 0xe0, 0xe, 0x0, 0xe0, 0xe, 0x0, 0x70,
    0x7, 0x83, 0x3f, 0xf0, 0xfc,

    /* U+0422 "Т" */
    0xff, 0xff, 0xff, 0xc1, 0xc0, 0xe, 0x0, 0x70,
    0x3, 0x80, 0x1c, 0x0, 0xe0, 0x7, 0x0, 0x38,
    0x1, 0xc0, 0xe, 0x0, 0x70, 0x3, 0x80,

    /* U+0423 "У" */
    0x60, 0x1b, 0x1, 0xdc, 0xc, 0x70, 0xe3, 0x86,
    0xe, 0x70, 0x37, 0x1, 0xf8, 0x7, 0x80, 0x1c,
    0x1, 0xc0, 0xe, 0x0, 0xe0, 0x6, 0x0,

    /* U+0424 "Ф" */
    0x3, 0x80, 0x3f, 0xe0, 0xff, 0xe3, 0x9c, 0xee,
    0x39, 0xfc, 0x71, 0xf8, 0xe3, 0xf1, 0xc7, 0xe3,
    0x8f, 0xe7, 0x3d, 0xce, 0x71, 0xff, 0xc1, 0xff,
    0x0, 0x70, 0x0, 0xe0, 0x0,

    /* U+0425 "Х" */
    0xc0, 0x6e, 0xe, 0x70, 0xe3, 0x9c, 0x3b, 0x81,
    0xf0, 0xe, 0x0, 0xf0, 0x1f, 0x3, 0xb8, 0x71,
    0xc7, 0xe, 0xe0, 0x6c, 0x6,

    /* U+0426 "Ц" */
    0xe0, 0x71, 0xc0, 0xe3, 0x81, 0xc7, 0x3, 0x8e,
    0x7, 0x1c, 0xe, 0x38, 0x1c, 0x70, 0x38, 0xe0,
    0x71, 0xc0, 0xe3, 0x81, 0xc7, 0x3, 0x8f, 0xff,
    0xff, 0xff, 0xc0, 0x3, 0x80, 0x7, 0x0, 0xe,
    0x0, 0x1c,

    /* U+0427 "Ч" */
    0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e,
    0x7, 0x70, 0x77, 0xff, 0x1f, 0xf0, 0x7, 0x0,
    0x70, 0x7, 0x0, 0x70, 0x7,

    /* U+0428 "Ш" */
    0xe0, 0xe0, 0xfc, 0x1c, 0x1f, 0x83, 0x83, 0xf0,
    0x70, 0x7e, 0xe, 0xf, 0xc1, 0xc1, 0xf8, 0x38,
    0x3f, 0x7, 0x7, 0xe0, 0xe0, 0xfc, 0x1c, 0x1f,
    0x83, 0x83, 0xf0, 0x70, 0x7f, 0xff, 0xff, 0xff,
    0xff, 0xc0,

    /* U+0429 "Щ" */
    0xe0, 0xe0, 0xe7, 0x7, 0x7, 0x38, 0x38, 0x39,
    0xc1, 0xc1, 0xce, 0xe, 0xe, 0x70, 0x70, 0x73,
    0x83, 0x83, 0x9c, 0x1c, 0x1c, 0xe0, 0xe0, 0xe7,
    0x7, 0x7, 0x38, 0x38, 0x39, 0xc1, 0xc1, 0xcf,
    0xff, 0xff, 0xff, 0xff, 0xfc, 0x0, 0x0, 0xe0,
    0x0, 0x7, 0x0, 0x0, 0x38, 0x0, 0x1, 0xc0,

    /* U+042A "Ъ" */
    0x7f, 0x0, 0x7f, 0x0, 0x7, 0x0, 0x7, 0x0,
    0x7, 0x0, 0x7, 0x0, 0x7, 0xfc, 0x7, 0xfe,
    0x7, 0xf, 0x7, 0x7, 0x7, 0x7, 0x7, 0xf,
    0x7, 0xfe, 0x7, 0xfc,

    /* U+042B "Ы" */
    0xe0, 0xf, 0xc0, 0x1f, 0x80, 0x3f, 0x0, 0x7e,
    0x0, 0xfc, 0x1, 0xff, 0xe3, 0xff, 0xe7, 0xe1,
    0xef, 0xc1, 0xdf, 0x83, 0xbf, 0xf, 0x7f, 0xfc,
    0xff, 0xf1, 0xc0,

    /* U+042C "Ь" */
    0xe0, 0x1c, 0x3, 0x80, 0x70, 0xe, 0x1, 0xc0,
    0x3f, 0xe7, 0xfe, 0xe1, 0xfc, 0x1f, 0x83, 0xf0,
    0xff, 0xfd, 0xff, 0x0,

    /* U+042D "Э" */
    0x3f, 0xf, 0xfc, 0xe1, 0xe0, 0xe, 0x0, 0x70,
    0x7, 0x1f, 0xf1, 0xff, 0x0, 0x70, 0x7, 0x0,
    0xee, 0x1e, 0xff, 0xc3, 0xf0,

    /* U+042E "Ю" */
    0xe0, 0x7c, 0x38, 0x3f, 0xce, 0x1c, 0x7b, 0x8e,
    0xe, 0xe3, 0x1, 0xf9, 0xc0, 0x7f, 0xf0, 0x1f,
    0xfc, 0x7, 0xe7, 0x1, 0xf8, 0xc0, 0x7e, 0x38,
    0x3b, 0x87, 0x1e, 0xe0, 0xff, 0x38, 0x1f, 0x0,

    /* U+042F "Я" */
    0x3f, 0xef, 0xff, 0xc3, 0xf0, 0x7e, 0xf, 0xe1,
    0xdf, 0xf8, 0xff, 0x18, 0xe7, 0x1d, 0xc3, 0xb8,
    0x7e, 0xe, 0xc1, 0xc0,

    /* U+0430 "а" */
    0x7e, 0x7f, 0xb0, 0xe0, 0x73, 0xff, 0xff, 0x8f,
    0xc7, 0xff, 0xbd, 0xc0,

    /* U+0431 "б" */
    0x0, 0x81, 0xf1, 0xf9, 0xe0, 0x70, 0x3b, 0xcf,
    0xfb, 0xcf, 0xe1, 0xf8, 0x7e, 0x1f, 0x87, 0x73,
    0x9f, 0xe1, 0xe0,

    /* U+0432 "в" */
    0xff, 0x3f, 0xee, 0x3b, 0x8e, 0xff, 0x3f, 0xee,
    0x1f, 0x87, 0xff, 0xff, 0xe0,

    /* U+0433 "г" */
    0xfe, 0xfe, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0,
    0xe0, 0xe0,

    /* U+0434 "д" */
    0x3f, 0xc7, 0xf8, 0xc7, 0x18, 0xe3, 0x1c, 0x63,
    0x8c, 0x73, 0xe, 0xff, 0xff, 0xff, 0x1, 0xe0,
    0x30,

    /* U+0435 "е" */
    0x1f, 0xf, 0xe7, 0x19, 0x83, 0xff, 0xdf, 0xf6,
    0x1, 0xc3, 0x3f, 0xc7, 0xc0,

    /* U+0436 "ж" */
    0x61, 0xc3, 0x38, 0xe3, 0x8e, 0x73, 0x83, 0x39,
    0x81, 0xff, 0xc1, 0xff, 0xf0, 0xe7, 0x38, 0xe3,
    0x8e, 0x61, 0xc3, 0x30, 0xe1, 0x80,

    /* U+0437 "з" */
    0x3f, 0x1f, 0xf4, 0x1c, 0x7, 0x1f, 0x87, 0xe0,
    0x1d, 0x7, 0xff, 0x8f, 0xc0,

    /* U+0438 "и" */
    0xe1, 0xf1, 0xf8, 0xfc, 0xfe, 0xdf, 0x4f, 0xe7,
    0xe3, 0xe1, 0xe0, 0xc0,

    /* U+0439 "й" */
    0x21, 0x18, 0x8f, 0xc3, 0xc0, 0x7, 0xf, 0x8f,
    0xc7, 0xe7, 0xf6, 0xfa, 0x7f, 0x3f, 0x1f, 0xf,
    0x6,

    /* U+043A "к" */
    0xe1, 0xb8, 0xee, 0x33, 0x9c, 0xfe, 0x3f, 0xce,
    0x33, 0x8e, 0xe1, 0xf8, 0x70,

    /* U+043B "л" */
    0x3f, 0xcf, 0xf3, 0x9c, 0xe7, 0x39, 0xce, 0x73,
    0x9d, 0xc7, 0xe1, 0xf0, 0x70,

    /* U+043C "м" */
    0xc0, 0x7c, 0x1f, 0x83, 0xf8, 0xff, 0xbf, 0xb6,
    0xf3, 0x9e, 0x73, 0xc0, 0x78, 0xc,

    /* U+043D "н" */
    0xe1, 0xf8, 0x7e, 0x1f, 0x87, 0xff, 0xff, 0xfe,
    0x1f, 0x87, 0xe1, 0xf8, 0x70,

    /* U+043E "о" */
    0x1e, 0x1f, 0xe7, 0x3b, 0x87, 0xe1, 0xf8, 0x7e,
    0x1d, 0xce, 0x7f, 0x87, 0x80,

    /* U+043F "п" */
    0xff, 0xff, 0xfe, 0x1f, 0x87, 0xe1, 0xf8, 0x7e,
    0x1f, 0x87, 0xe1, 0xf8, 0x70,

    /* U+0440 "р" */
    0xef, 0x3f, 0xef, 0x3f, 0x87, 0xe1, 0xf8, 0x7e,
    0x1f, 0xcf, 0xff, 0xbb, 0xce, 0x3, 0x80, 0xe0,
    0x38, 0x0,

    /* U+0441 "с" */
    0x1f, 0x3f, 0xdc, 0x5c, 0xe, 0x7, 0x3, 0x80,
    0xe2, 0x7f, 0x8f, 0x80,

    /* U+0442 "т" */
    0xff, 0xff, 0xf1, 0xc0, 0x70, 0x1c, 0x7, 0x1,
    0xc0, 0x70, 0x1c, 0x7, 0x0,

    /* U+0443 "у" */
    0x60, 0xd8, 0x37, 0x1d, 0xc6, 0x31, 0x8e, 0xc1,
    0xb0, 0x7c, 0xe, 0x3, 0x80, 0xc0, 0x70, 0x18,
    0x6, 0x0,

    /* U+0444 "ф" */
    0x3, 0x80, 0x7, 0x0, 0xe, 0x0, 0x1c, 0x3,
    0xbb, 0x8f, 0xff, 0xbd, 0xf7, 0xf1, 0xc7, 0xe3,
    0x8f, 0xc7, 0x1f, 0x8e, 0x3f, 0xbe, 0xf7, 0xff,
    0xc7, 0x77, 0x0, 0xe0, 0x1, 0xc0, 0x3, 0x80,
    0x7, 0x0,

    /* U+0445 "х" */
    0xc1, 0xf1, 0xdd, 0xc7, 0xc1, 0xc0, 0xf0, 0xf8,
    0xee, 0xe3, 0xe0, 0xc0,

    /* U+0446 "ц" */
    0xe3, 0x9c, 0x73, 0x8e, 0x71, 0xce, 0x39, 0xc7,
    0x38, 0xe7, 0x1c, 0xff, 0xff, 0xfc, 0x1, 0x80,
    0x30,

    /* U+0447 "ч" */
    0xe3, 0xf1, 0xf8, 0xfc, 0x7e, 0x3b, 0xfc, 0xfe,
    0x7, 0x3, 0x81, 0xc0,

    /* U+0448 "ш" */
    0xe7, 0x3f, 0x39, 0xf9, 0xcf, 0xce, 0x7e, 0x73,
    0xf3, 0x9f, 0x9c, 0xfc, 0xe7, 0xff, 0xff, 0xff,
    0xc0,

    /* U+0449 "щ" */
    0xe7, 0x1d, 0xce, 0x3b, 0x9c, 0x77, 0x38, 0xee,
    0x71, 0xdc, 0xe3, 0xb9, 0xc7, 0x73, 0x8e, 0xff,
    0xff, 0xff, 0xfc, 0x0, 0x18, 0x0, 0x30,

    /* U+044A "ъ" */
    0xfc, 0xf, 0xc0, 0x1c, 0x1, 0xfe, 0x1f, 0xf1,
    0xc7, 0x1c, 0x71, 0xc7, 0x1f, 0xe1, 0xfc,

    /* U+044B "ы" */
    0xe0, 0x3f, 0x1, 0xf8, 0xf, 0xfe, 0x7f, 0xfb,
    0xf1, 0xdf, 0x8e, 0xfc, 0x77, 0xff, 0x3f, 0xf1,
    0xc0,

    /* U+044C "ь" */
    0xe0, 0x70, 0x38, 0x1f, 0xef, 0xff, 0x1f, 0x8f,
    0xc7, 0xff, 0x7f, 0x0,

    /* U+044D "э" */
    0x3c, 0x7f, 0xb0, 0xc0, 0x73, 0xf9, 0xfc, 0xf,
    0x86, 0xff, 0x3e, 0x0,

    /* U+044E "ю" */
    0xe1, 0xe3, 0x8f, 0xee, 0x63, 0xb9, 0x87, 0xfe,
    0x1f, 0xf8, 0x7e, 0x61, 0xf9, 0x8e, 0xe3, 0xfb,
    0x87, 0x80,

    /* U+044F "я" */
    0x3f, 0xff, 0xf8, 0xfc, 0x7e, 0x3b, 0xfc, 0x7e,
    0x67, 0x73, 0xb1, 0xc8, 0x0,

    /* U+0451 "ё" */
    0x3f, 0xf, 0xc0, 0x0, 0x0, 0x1f, 0x1f, 0xe7,
    0x1b, 0x83, 0xff, 0xff, 0xfe, 0x1, 0xc2, 0x7f,
    0xc7, 0xc0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 87, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 79, .box_w = 4, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 8, .adv_w = 143, .box_w = 7, .box_h = 6, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 14, .adv_w = 192, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 32, .adv_w = 192, .box_w = 11, .box_h = 19, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 59, .adv_w = 302, .box_w = 17, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 91, .adv_w = 232, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 114, .adv_w = 78, .box_w = 3, .box_h = 6, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 117, .adv_w = 115, .box_w = 5, .box_h = 18, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 129, .adv_w = 115, .box_w = 5, .box_h = 18, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 141, .adv_w = 145, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 149, .adv_w = 192, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 162, .adv_w = 79, .box_w = 3, .box_h = 5, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 164, .adv_w = 139, .box_w = 6, .box_h = 2, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 166, .adv_w = 79, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 168, .adv_w = 100, .box_w = 7, .box_h = 16, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 182, .adv_w = 192, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 202, .adv_w = 192, .box_w = 9, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 218, .adv_w = 192, .box_w = 11, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 238, .adv_w = 192, .box_w = 11, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 258, .adv_w = 192, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 278, .adv_w = 192, .box_w = 10, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 296, .adv_w = 192, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 316, .adv_w = 192, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 334, .adv_w = 192, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 354, .adv_w = 192, .box_w = 11, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 374, .adv_w = 79, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 378, .adv_w = 79, .box_w = 3, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 383, .adv_w = 192, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 396, .adv_w = 192, .box_w = 10, .box_h = 6, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 404, .adv_w = 192, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 417, .adv_w = 147, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 433, .adv_w = 304, .box_w = 17, .box_h = 18, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 472, .adv_w = 238, .box_w = 15, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 499, .adv_w = 220, .box_w = 11, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 519, .adv_w = 218, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 540, .adv_w = 244, .box_w = 13, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 563, .adv_w = 191, .box_w = 10, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 581, .adv_w = 180, .box_w = 10, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 599, .adv_w = 236, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 622, .adv_w = 247, .box_w = 13, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 645, .adv_w = 90, .box_w = 3, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 651, .adv_w = 113, .box_w = 7, .box_h = 14, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 664, .adv_w = 213, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 685, .adv_w = 180, .box_w = 10, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 703, .adv_w = 278, .box_w = 15, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 730, .adv_w = 239, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 751, .adv_w = 251, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 776, .adv_w = 209, .box_w = 11, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 796, .adv_w = 251, .box_w = 14, .box_h = 18, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 828, .adv_w = 220, .box_w = 11, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 848, .adv_w = 202, .box_w = 12, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 869, .adv_w = 199, .box_w = 13, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 892, .adv_w = 236, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 913, .adv_w = 228, .box_w = 14, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 938, .adv_w = 356, .box_w = 21, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 975, .adv_w = 215, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 996, .adv_w = 198, .box_w = 13, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1019, .adv_w = 194, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1039, .adv_w = 113, .box_w = 5, .box_h = 18, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 1051, .adv_w = 100, .box_w = 7, .box_h = 16, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1065, .adv_w = 113, .box_w = 5, .box_h = 18, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1077, .adv_w = 192, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 1090, .adv_w = 160, .box_w = 10, .box_h = 2, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1093, .adv_w = 160, .box_w = 4, .box_h = 5, .ofs_x = 2, .ofs_y = 11},
    {.bitmap_index = 1096, .adv_w = 175, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1108, .adv_w = 192, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1126, .adv_w = 151, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1138, .adv_w = 192, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1156, .adv_w = 173, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1169, .adv_w = 116, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1183, .adv_w = 193, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1201, .adv_w = 187, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1217, .adv_w = 82, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1223, .adv_w = 83, .box_w = 6, .box_h = 18, .ofs_x = -2, .ofs_y = -4},
    {.bitmap_index = 1237, .adv_w = 172, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1253, .adv_w = 102, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1262, .adv_w = 281, .box_w = 15, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1281, .adv_w = 187, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1293, .adv_w = 184, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1306, .adv_w = 192, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1324, .adv_w = 192, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1342, .adv_w = 125, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1351, .adv_w = 156, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1364, .adv_w = 123, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1377, .adv_w = 185, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1389, .adv_w = 169, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1402, .adv_w = 273, .box_w = 17, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1424, .adv_w = 175, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1436, .adv_w = 168, .box_w = 10, .box_h = 14, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1454, .adv_w = 152, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1466, .adv_w = 125, .box_w = 7, .box_h = 18, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1482, .adv_w = 92, .box_w = 3, .box_h = 18, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 1489, .adv_w = 125, .box_w = 7, .box_h = 18, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1505, .adv_w = 192, .box_w = 10, .box_h = 3, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 1509, .adv_w = 121, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 1514, .adv_w = 191, .box_w = 10, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1537, .adv_w = 238, .box_w = 15, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1564, .adv_w = 215, .box_w = 11, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1584, .adv_w = 220, .box_w = 11, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1604, .adv_w = 179, .box_w = 10, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1622, .adv_w = 256, .box_w = 16, .box_h = 18, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1658, .adv_w = 191, .box_w = 10, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1676, .adv_w = 324, .box_w = 19, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1710, .adv_w = 203, .box_w = 12, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1731, .adv_w = 239, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1752, .adv_w = 239, .box_w = 12, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1781, .adv_w = 216, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1802, .adv_w = 241, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1825, .adv_w = 278, .box_w = 15, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1852, .adv_w = 247, .box_w = 13, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1875, .adv_w = 251, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1900, .adv_w = 245, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1921, .adv_w = 209, .box_w = 11, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1941, .adv_w = 218, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1962, .adv_w = 199, .box_w = 13, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1985, .adv_w = 212, .box_w = 13, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2008, .adv_w = 283, .box_w = 15, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2037, .adv_w = 215, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2058, .adv_w = 260, .box_w = 15, .box_h = 18, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 2092, .adv_w = 223, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2113, .adv_w = 342, .box_w = 19, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2147, .adv_w = 357, .box_w = 21, .box_h = 18, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 2195, .adv_w = 258, .box_w = 16, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2223, .adv_w = 288, .box_w = 15, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2250, .adv_w = 215, .box_w = 11, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2270, .adv_w = 218, .box_w = 12, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2291, .adv_w = 335, .box_w = 18, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2323, .adv_w = 220, .box_w = 11, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2343, .adv_w = 180, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2355, .adv_w = 189, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2374, .adv_w = 182, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2387, .adv_w = 146, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2397, .adv_w = 198, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 2414, .adv_w = 178, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2427, .adv_w = 264, .box_w = 17, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2449, .adv_w = 166, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2462, .adv_w = 193, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2474, .adv_w = 193, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2491, .adv_w = 179, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2504, .adv_w = 191, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2517, .adv_w = 219, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2531, .adv_w = 195, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2544, .adv_w = 189, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2557, .adv_w = 194, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2570, .adv_w = 196, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 2588, .adv_w = 156, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2600, .adv_w = 151, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2613, .adv_w = 173, .box_w = 10, .box_h = 14, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 2631, .adv_w = 268, .box_w = 15, .box_h = 18, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 2665, .adv_w = 179, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2677, .adv_w = 199, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 2694, .adv_w = 184, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2706, .adv_w = 266, .box_w = 13, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2723, .adv_w = 276, .box_w = 15, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 2746, .adv_w = 203, .box_w = 12, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2761, .adv_w = 248, .box_w = 13, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2778, .adv_w = 177, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2790, .adv_w = 164, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2802, .adv_w = 261, .box_w = 14, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2820, .adv_w = 180, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 2833, .adv_w = 178, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0x351
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 176, .range_length = 850, .glyph_id_start = 96,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 2, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    },
    {
        .range_start = 1040, .range_length = 64, .glyph_id_start = 98,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 1105, .range_length = 1, .glyph_id_start = 162,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 1, 2, 0, 0, 0, 3,
    2, 4, 0, 5, 0, 6, 7, 6,
    8, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 9, 9, 0, 0, 0,
    10, 11, 12, 13, 14, 11, 15, 16,
    17, 0, 0, 18, 19, 20, 0, 0,
    11, 21, 11, 22, 23, 24, 25, 26,
    26, 27, 28, 29, 4, 0, 0, 0,
    6, 0, 30, 31, 32, 33, 34, 35,
    36, 30, 33, 33, 37, 38, 30, 30,
    31, 31, 39, 40, 41, 42, 36, 43,
    43, 44, 43, 45, 4, 0, 7, 0,
    46, 47, 48, 49, 50, 51, 52, 47,
    53, 50, 0, 0, 53, 0, 0, 0,
    54, 0, 55, 56, 57, 58, 0, 59,
    52, 0, 0, 52, 60, 0, 60, 54,
    54, 0, 61, 62, 63, 64, 65, 66,
    0, 63, 67, 67, 0, 67, 67, 67,
    62, 67, 62, 68, 69, 70, 0, 71,
    65, 67, 67, 65, 72, 67, 72, 62,
    62, 67, 66
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 0, 1, 2, 0, 0, 3, 4,
    2, 5, 6, 7, 0, 8, 9, 8,
    10, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 11, 11, 0, 0, 0,
    12, 13, 14, 15, 13, 15, 15, 15,
    13, 15, 15, 16, 15, 15, 15, 15,
    13, 15, 13, 15, 17, 18, 19, 20,
    20, 21, 22, 23, 5, 24, 6, 0,
    8, 0, 25, 26, 27, 27, 27, 28,
    27, 26, 26, 29, 26, 26, 30, 30,
    27, 30, 27, 30, 31, 32, 33, 34,
    34, 35, 34, 36, 9, 15, 6, 0,
    37, 0, 38, 0, 0, 0, 39, 0,
    0, 40, 0, 0, 0, 41, 0, 0,
    42, 0, 0, 42, 43, 44, 0, 45,
    0, 46, 0, 0, 43, 0, 0, 47,
    0, 48, 49, 50, 51, 51, 52, 53,
    0, 54, 51, 51, 51, 55, 51, 51,
    53, 51, 51, 53, 56, 57, 0, 58,
    51, 59, 51, 51, 56, 51, 51, 60,
    51, 61, 53
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 0, 0, 0, 0, 2, -3, 0,
    -3, 3, 0, -2, 0, 0, 0, 10,
    0, -3, 0, -3, 0, -3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -16, 0, -18, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -18, 0, -13, -21, 0, 0, 0, -5,
    -10, -16, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 10, 0, -8, 0, -11, -4, -10,
    0, 0, 2, 0, -4, 0, 0, 0,
    5, 0, 0, -5, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 2,
    0, 0, 0, 0, 13, 0, 0, 0,
    13, 0, 10, -3, 0, 0, 0, 0,
    13, 0, 10, 3, 11, 6, 0, 0,
    0, -3, 0, 26, 0, 0, 0, 0,
    0, 0, 0, 2, 0, 0, 0, 0,
    -3, 11, 0, 3, 0, 0, 0, 0,
    0, 0, 0, -1, 0, 0, 0, 0,
    0, 0, 0, 0, -3, 0, 0, 0,
    0, 0, 0, -16, -21, -35, -3, 3,
    0, -23, 0, -18, 0, 5, 0, 3,
    -4, 6, -2, 0, 0, 8, -7, 8,
    0, 0, -2, 8, 0, 6, 4, 0,
    0, -20, 0, 0, 0, 0, 0, 0,
    -4, 0, 0, 0, 0, 0, 0, 0,
    -6, 0, 0, 0, 3, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -18,
    0, -14, 21, 0, -23, -12, 6, 0,
    11, 3, -21, -6, -18, 3, -22, 3,
    0, -1, 0, -6, -6, 6, 0, 1,
    -10, -2, -15, 5, 0, -21, 6, 0,
    0, 0, -11, -20, 0, 3, 0, 0,
    0, -2, 0, 0, 0, -5, 0, 0,
    -13, -12, 5, -18, 0, 0, -3, 0,
    0, 0, 0, 0, -21, -14, 0, 0,
    -6, -12, 0, -6, 0, -9, -6, -15,
    0, -16, -8, -17, 0, 0, 0, 0,
    5, 0, 0, 0, 2, 0, 0, -6,
    -8, -3, -18, -5, -10, 0, -20, -2,
    -15, -32, -8, -16, 0, 0, 0, 0,
    0, -8, 5, 0, -13, 0, -5, -8,
    0, 0, 0, 0, 0, 0, 0, 0,
    13, 0, -34, -21, -14, -6, 16, -3,
    -6, 0, -13, 0, 13, 0, 13, 3,
    11, 5, 0, -19, 0, -19, 0, 0,
    -19, -19, -3, -19, -10, -16, -19, 1,
    -6, 0, 0, 0, -3, 13, 0, 3,
    0, 0, 0, -19, 0, -19, 0, -19,
    0, 0, 0, -10, -16, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -3, 0,
    -6, 18, 0, -3, 0, 0, 0, 6,
    0, -10, 0, -10, 0, -12, 0, 0,
    0, 0, 0, 2, 6, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 3, 2, -27, -3, -3, 0,
    4, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 5, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    0, -12, 0, -3, 0, -3, 0, -5,
    0, -11, 0, -14, 0, -6, -9, -14,
    -5, 0, 0, 0, 0, 0, 6, 0,
    0, 0, 0, 0, 0, 0, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -23, 6, -6,
    10, 0, -18, -5, 0, 0, 6, -3,
    -25, -2, -19, -5, -21, -3, 0, 0,
    0, -2, -3, 0, 0, -3, -5, 0,
    -9, -7, -1, -27, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -3, 1, 0, 0, 0,
    0, -2, 0, -2, 0, -3, 0, -3,
    -3, -4, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -7, 0, 0, 0,
    3, -11, 6, 0, 6, -7, -5, 0,
    -1, -5, -3, 0, -6, -5, -5, -3,
    0, -6, 0, -11, -7, 0, 0, -3,
    -7, -4, -8, -3, -6, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 2, 0, 3, -1, 11,
    0, 2, 0, -4, 0, 4, -3, -2,
    0, -1, -2, -1, 0, 0, -2, 0,
    -1, -2, 0, 0, -2, -2, 0, -3,
    0, 0, 3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 2, 0, 0, 0, 0,
    5, 0, -10, -3, -8, 0, 3, -4,
    -18, 0, -17, -6, 3, 0, 2, -4,
    0, -3, 0, -6, 13, -6, 0, 0,
    -3, -5, 0, -4, -2, -4, -11, 4,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0,
    0, -4, 0, -3, -2, -5, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -5, 0, 0, 0,
    0, 0, 0, 0, -6, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 8, 0, 0, 0, 0, 2,
    -6, 5, -11, 11, 0, 3, -9, -8,
    0, 10, -7, -11, -3, -6, -3, -7,
    1, 0, 0, 8, -4, -4, 0, 0,
    -3, -6, -3, -10, -12, -5, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -19, 4, -11,
    14, 1, -25, -12, -5, 0, 13, -5,
    -42, -9, -33, -6, -38, 0, 0, 0,
    0, -2, -5, 0, 0, -1, -10, -3,
    -14, -6, 0, -24, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 3, 0, 0, -5,
    0, -3, 2, -17, -9, -19, -2, 2,
    -2, -23, 0, -21, 0, -6, 0, 0,
    -10, -1, -6, 0, -7, 0, -8, 0,
    0, -3, -7, 5, -3, 2, -5, -6,
    12, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, -6, 7, 0, 0, -2, -4, 0,
    2, -1, -6, 0, -4, -3, -3, -1,
    0, -2, 0, -4, 0, 0, 0, -3,
    0, 0, -1, -3, -2, 3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -5, -3, 2, 2,
    0, 1, 0, -2, 0, -3, 0, -5,
    0, -4, -3, -6, -3, 0, 0, 0,
    0, -2, 0, 0, -1, -2, 0, -3,
    -1, -1, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 2, 0, 0, -8, 0,
    13, 5, -21, -15, -16, -10, 6, -14,
    -25, 0, -19, -7, 4, 0, 5, 0,
    4, -1, 0, -25, 18, -25, -11, 0,
    -25, -25, -11, -24, -24, -25, -25, 5,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -6,
    0, -3, 0, 0, 0, -2, 0, -8,
    0, 0, 0, 0, -3, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 3, 0, 0,
    -11, 0, 10, 3, -18, -16, -6, -11,
    5, -6, -19, 0, -19, -4, 5, 0,
    0, -5, 2, 0, 0, -19, 16, -20,
    -6, 0, -19, -20, -5, -16, -10, -19,
    -18, 5, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 6, 0, 0, 0, 0, 3,
    -4, 3, -8, 6, 0, 2, -9, -5,
    0, 6, -3, 0, -3, -5, 0, -1,
    0, 0, 0, 6, -3, -6, 0, 0,
    -3, -7, 0, -9, -8, -6, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 13,
    0, 0, -3, 0, 11, 6, -22, -17,
    -8, -12, 11, -14, -21, 11, -14, -7,
    6, 0, 2, 0, 2, 0, 0, -25,
    0, -27, -11, 0, -25, -26, -12, -24,
    -23, -26, -26, 6, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 6, -2, 3, -6, 8, 0, 2,
    -5, -3, 0, 6, -3, 0, 0, -3,
    0, 0, 0, 0, -3, 0, -5, -3,
    0, 0, -3, -6, -3, -10, -5, -7,
    -1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -5,
    0, 0, 0, 0, -4, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, 0, -9, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -3, -7, -6, 5, 0,
    0, -7, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, 0, -2, 0, -3,
    -4, -3, -11, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    3, 0, 3, -3, 3, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -1, 0, -3, 1, 0,
    0, 0, 1, 0, 3, 5, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 8, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -3, -6, 0, 4, 3, 0,
    -3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -1, 0, 0, 0, -1, 0, -3, -1,
    -2, -9, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 7, 0, 0, -3, 0, 17,
    11, -8, -3, 0, 2, 16, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, -4, -7, 0, 0,
    -2, -9, 0, -3, -6, -3, 16, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 4, -9, 6, 0, -5,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, 0, -3, 0,
    0, 0, -3, -5, 0, -6, -6, -2,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -14, -6, -1, -3, 21, -11,
    3, -2, 11, 0, -6, -3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -5, 0, 0, -2, -3, 0, 0, -2,
    -4, 0, -4, 0, 0, -14, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 4, 0, 0, -5, 0,
    5, 12, -7, -6, -5, 5, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -2, 0, -3, 9, 0,
    0, -2, 9, 0, 10, 2, 2, 11,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, -2,
    0, 0, 0, -3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    0, -3, -2, -2, -3, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 26, 7, 6, -2, 16, 1,
    2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 4, -2,
    -1, 0, 0, 0, -9, 0, 3, 3,
    1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -3, 0, 0,
    6, -15, -6, -8, 0, -6, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -3, 0, -3, 3, 0, 0,
    -3, 5, 0, 13, -3, -3, 3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 4, 5, -8,
    5, 0, -8, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -1,
    0, -4, 0, 0, 0, -2, 0, 0,
    -3, 0, -2, -2, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -11, 0, 0, -8,
    0, 0, 0, 2, 0, 0, 0, 0,
    0, 0, 0, 0, -2, 0, -3, 0,
    0, 0, -2, 0, 0, -3, -2, 0,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 2, 0,
    -21, -18, -39, 0, 8, -3, -27, 0,
    -21, 1, 5, 0, 5, 0, 6, -1,
    0, -2, 0, -11, 3, 0, 0, -6,
    4, 0, 3, -2, 0, 0, -24, 0,
    0, 0, 0, 5, 0, 0, 0, 0,
    0, -2, 0, 0, 0, -11, 0, 0,
    0, 3, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 2, 0, 3, -1, 11,
    0, 2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 2, -4, 0, 0, 0, 0,
    -2, 0, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -20, 6, -5, 10, 0, -18, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -24,
    0, 0, 0, 0, -7, -27, -18, -5,
    -11, 0, 0, 0, -6, 0, 0, 0,
    0, 0, -10, -8, -6, -10, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -3, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -3, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 2, -3, 2, 0, -3, 0, -3,
    -10, -3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -29,
    -11, 0, -10, -3, 0, 0, 0, 0,
    0, -3, -38, -18, -26, -40, -38, -32,
    -43, -22, -29, -26, -34, -42, -38, 0,
    -13, 0, 0, 0, 0, 0, 0, -16,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -10, 0, 0, -8, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -3, -6,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 2, -6, 3, -17, 11, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -5, 0, 5, 0, -4, 0, 0,
    -3, 5, 3, 0, 0, -8, 0, 0,
    -3, 0, 0, -10, -9, -6, -5, 0,
    0, 0, 0, 0, 0, 0, -3, 0,
    -11, -6, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -6, -6,
    0, -1, 0, -14, -6, -8, 0, 0,
    0, 0, 0, 0, -3, 0, 0, -3,
    0, 0, 0, 0, 0, 0, 3, 0,
    0, 0, 0, -3, 2, -17, -9, -19,
    -3, 2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 12, -24, -16, 0, -13, -3,
    -6, 0, -10, 0, 0, 0, -4, 0,
    -3, 0, -6, 0, 0, 0, 1, -3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 3, -6, 6, 0, 6, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -5, 0, 0, 0, -4, -3, 0, -6,
    0, 0, 0, -3, 0, 0, 0, -3,
    0, 0, 0, -6, -3, 0, 0, 0,
    2, 0, 0, 0, 0, 11, 0, -20,
    -15, -16, -11, 6, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 5, -27, -13, 0,
    -6, -12, 4, 0, 0, 0, 0, 0,
    -25, -10, -25, -24, -25, -19, -27, -10,
    -24, -25, -19, -19, -27, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -19, 0, 0, -10, 0,
    0, 0, 0, 0, 0, 0, 0, -16,
    0, -21, -14, -26, -2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 3,
    -4, 3, -8, 6, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -5,
    0, 0, 0, -8, 0, 0, 0, 0,
    0, 0, 0, -8, 0, 0, -3, 0,
    0, 0, -8, -8, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -3, 0, 0,
    0, -30, -18, -3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -5, 0, 0, 0, 0, -3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -9, 0, 0, 0, 0, 0, -16, -11,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -3, -6,
    -5, 5, 0, 0, -3, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -11, 0, -3,
    0, 0, 0, -29, -18, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    0, -3, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -29, -21, 2, -3, 0, 0, 0, 0,
    0, 3, 0, 0, 0, 3, 0, 0,
    2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -45, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -11, 0, 0, 0, -6, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    3, -6, 5, 0, 0, 0, 0, 2,
    0, -2, 0, 0, 0, 0, 0, 0,
    -10, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -24, -21, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -3, -6, 0, 4, 3, 0,
    -3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -8, 0, 0, 0, 0, 0, -32,
    -24, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -3, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -19, -10, 0, -6,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 3, 0, 3, 0,
    3, 2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -22, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -11, 0, 0, 0, 0, -2, -6,
    0, 0, 0, 0, 0, 0, 0, -3,
    -2, 0, -2, 3, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 3,
    -12, -5, -8, 0, -6, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 3, 0, -14,
    0, 0, -3, -22, -10, -3, 0, 0,
    0, -3, 0, 0, -5, -3, -2, -10,
    3, 0, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 5, -8, 5,
    0, -8, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, 0, 0, 0, 0,
    -16, -11, 0, 0, 0, 0, -2, 2,
    0, 4, -3, 5, 0, 0, -3, 0,
    3, 3, 0, 0, -19, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 2, -35, -32, 0,
    -18, 0, 0, 0, 0, 0, 0, 0,
    3, 0, -8, -8, 3, 0, 0, 3
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 72,
    .right_class_cnt     = 61,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 4,
    .bpp = 1,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif

};

extern const lv_font_t rus20;


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t rus20 = {
#else
lv_font_t rus20 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 23,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if RUS20*/

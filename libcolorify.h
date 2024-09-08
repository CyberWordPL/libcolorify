#ifndef LIBCOLORIFY_HEADER
#define LIBCOLORIFY_HEADER

#include <stdio.h>

typedef enum
{
    LIBCOLORIFY_BLACK = 30,
    LIBCOLORIFY_RED,
    LIBCOLORIFY_GREEN,
    LIBCOLORIFY_YELLOW,
    LIBCOLORIFY_BLUE,
    LIBCOLORIFY_MAGENTA,
    LIBCOLORIFY_CYAN,
    LIBCOLORIFY_WHITE,
    LIBCOLORIFY_BRIGHT_BLACK = 90,
    LIBCOLORIFY_BRIGHT_RED,
    LIBCOLORIFY_BRIGHT_GREEN,
    LIBCOLORIFY_BRIGHT_YELLOW,
    LIBCOLORIFY_BIT_BRIGHT_BLUE,
    LIBCOLORIFY_BRIGHT_MAGENTA,
    LIBCOLORIFY_BRIGHT_CYAN,
    LIBCOLORIFY_BRIGHT_WHITE

} libcolorify_color_4b_t;

typedef enum
{
    LIBCOLORIFY_FOREGROUND_COLOR,
    LIBCOLORIFY_BACKGROUND_COLOR = 10,
} libcolorify_ground_t;

#ifdef __LIBCOLORIFY_INTERNAL

void __file_set_default_color(FILE *f, libcolorify_ground_t grn);
void __file_set_color_4b(FILE *f, libcolorify_color_4b_t col, libcolorify_ground_t grn);
void __file_set_color_8b(FILE *f, unsigned char col, libcolorify_ground_t grn);
void __file_set_color_24b(FILE *f, unsigned char r, unsigned char g, unsigned char b, libcolorify_ground_t grn);
#endif

void set_default_color(libcolorify_ground_t grn);
void set_color_4b(libcolorify_color_4b_t col, libcolorify_ground_t grn);
void set_color_8b(unsigned char col, libcolorify_ground_t grn);
void set_color_24b(unsigned char r, unsigned char g, unsigned char b, libcolorify_ground_t grn);

#endif

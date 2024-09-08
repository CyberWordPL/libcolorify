#include <stdio.h>
#include <libcolorify.h>

void __file_set_default_color(FILE *f, libcolorify_ground_t grn)
{
    const int func_code = 39;
    fprintf(f, "\x1b[%dm", func_code + (int)grn);
}

void __file_set_color_4b(FILE *f, libcolorify_color_4b_t col, libcolorify_ground_t grn)
{
    fprintf(f, "\x1b[%dm", (int)col + (int)grn);
}

void __file_set_color_8b(FILE *f, unsigned char col, libcolorify_ground_t grn)
{
    const int func_code = 38;
    fprintf(f, "\x1b[%d;5;%um", func_code + (int)grn, col);
}

void __file_set_color_24b(FILE *f, unsigned char r, unsigned char g, unsigned char b, libcolorify_ground_t grn)
{
    const int func_code = 38;
    fprintf(f, "\x1b[%u;2;%u;%u;%um", func_code + grn, r, g, b);
}

void set_default_color(libcolorify_ground_t grn)
{
    __file_set_default_color(stdout, grn);
}

void set_color_4b(libcolorify_color_4b_t col, libcolorify_ground_t grn)
{
    __file_set_color_4b(stdout, col, grn);
}

void set_color_8b(unsigned char col, libcolorify_ground_t grn)
{
    __file_set_color_8b(stdout, col, grn); 
}

void set_color_24b(unsigned char r, unsigned char g, unsigned char b, libcolorify_ground_t grn)
{
    __file_set_color_24b(stdout, r, g, b, grn);    
}

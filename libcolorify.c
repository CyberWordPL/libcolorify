#include <stdio.h>
#include <libcolorify.h>

void set_default_color(libcolorify_ground_t grn)
{
    const int func_code = 39;
    fprintf(stdout, "\x1b[%dm", func_code + (int)grn);
}

void set_color_4b(libcolorify_color_4b_t col, libcolorify_ground_t grn)
{
    fprintf(stdout, "\x1b[%dm", (int)col + (int)grn);
}

void set_color_8b(unsigned char col, libcolorify_ground_t grn)
{
    const int func_code = 38;
    fprintf(stdout, "\x1b[%d;5;%um", func_code + (int)grn, col);
}

void set_color_24b(unsigned char r, unsigned char g, unsigned char b, libcolorify_ground_t grn)
{
    (void)grn;
    const int func_code = 38;
    fprintf(stdout, "\x1b[%u;2;%u;%u;%um", func_code + grn, r, g, b);
    //fprintf(stdout, "%u %u %u", r, g, b);
}

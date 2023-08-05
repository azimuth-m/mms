#include <stdio.h>
#include <inttypes.h>

#ifndef PPM_H
#define PPM_H 1

struct Pixel_Data {
        uint8_t b, g, r;
};

union pixelUnion {
        struct Pixel_Data pixel;
        uint32_t manipulatePixel;
};

struct PPM_Image_Buffer {
        struct Pixel_Data *data;
        uint16_t component_range;
        uint32_t w, h;
};

int read_ppm_color_bitmap(char *, struct PPM_Image_Buffer *);
int write_ppm_color_bitmap(char *, struct PPM_Image_Buffer *);
void printImageBuffer(struct PPM_Image_Buffer);
void filter_color_component(struct PPM_Image_Buffer *, uint32_t);
void luminance_black_and_white(struct PPM_Image_Buffer *);
#endif

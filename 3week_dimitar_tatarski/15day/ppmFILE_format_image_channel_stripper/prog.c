#include <stdlib.h>
#include "ppm.h"

int
main(int argc, char *argv[])
{
        /* Takes 1st arg as input file
         * Takes 2nd arg as output file
         */

        uint32_t mask = 0xff000000;
        /*                 ^ ^ ^ ^
         *                 | | | |-Blue Channel
         *                 | | |
         *                 | | |-Green Channel
         *                 | | 
         *                 | |-Red Channel
         *                 |
         *                 |-Keep the MSB set (at 255)
         */ 

        printf("\nMask format:\nrrggbb\n00 - clear a given channel\nff - keep a givven channel\nEnter Mask without 0x: ");
        scanf("%x", &mask);

        mask |= 0xff000000; /* Make sure to set the MSB of the mask.
                             * WE do not keep information on alpha channel,
                             * but have a necessary byte to pad the pixel 
                             */

        struct PPM_Image_Buffer buf;
        read_ppm_color_bitmap(argv[1], &buf);
        //printImageBuffer(buf);
        //filter_color_component(&buf, mask); //strip channel
        luminance_black_and_white(&buf); //convert to b&w using luminance method
        write_ppm_color_bitmap(argv[2], &buf);
        //printImageBuffer(buf);
        free(buf.data);
        return 0;
}

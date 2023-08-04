/* PPM Image channel reader, writer and stripper.
 * Created by azimuth-m
 * Works with both P6 and P3 .ppm file formats.
 *  
 */
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "ppm.h"

char ppm_id[3];

static void
readP3(FILE *fp, struct PPM_Image_Buffer *buf)
{
        for(size_t i = 0; i < (buf->w)*(buf->h); i++) {
                fscanf(fp, "%hhu", &(buf->data[i].r));
                fscanf(fp, "%hhu", &(buf->data[i].g));
                fscanf(fp, "%hhu", &(buf->data[i].b));
        }
}

static void
readP6(FILE *fp, struct PPM_Image_Buffer *buf)
{
        fgetc(fp); /* Need to seek the cursor. Neznam zashto taka raboti i za p6 */
        for(size_t i = 0; i < (buf->w)*(buf->h); i++) {
                buf->data[i].r = (uint8_t)fgetc(fp);
                buf->data[i].g = (uint8_t)fgetc(fp);
                buf->data[i].b = (uint8_t)fgetc(fp);
        }

}

int
read_ppm_color_bitmap(char *filename, struct PPM_Image_Buffer *buf)
{
        FILE *fp = fopen(filename, "r");
        /* Get line 1 (identifier) */
        fgets(ppm_id, 3, fp);
        if ((strcmp(ppm_id, "P3") != 0) && (strcmp(ppm_id, "P6")!=0)) {
                perror("File is not a ppm P3 or P6 format");
                exit (-1);
        }
        fscanf(fp, "%u", &(buf->w)); 
        fscanf(fp, "%u", &(buf->h)); 
        buf->data = malloc(sizeof(struct Pixel_Data) * buf->w * buf->h);
        if (!(buf->data)) {
                perror("Unable to allocate memory for Pixel Data");
                exit(-1);
        }

        /* Get line 3 (pixel component max value) */
        fscanf(fp, "%hu", &(buf->component_range)); 
        /* Start storing pixels */
        if (strcmp(ppm_id, "P3") == 0)
                readP3(fp, buf);
        else
                readP6(fp, buf);
        fclose(fp);
        return 0;
}

void
printImageBuffer(struct PPM_Image_Buffer buf)
{

        printf("\n%u %u\n%hu\n", buf.w, buf.h, buf.component_range);
        for(size_t i = 0; i < (buf.w) * (buf.h); i++) {
                printf("%hhu ", buf.data[i].r);
                printf("%hhu ", buf.data[i].g);
                printf("%hhu\n", buf.data[i].b );
        }
}

static void
writeP3(FILE *fp, struct PPM_Image_Buffer *buf)
{
        fprintf(fp, "\n%u %u\n%hu\n", buf->w, buf->h, (buf->component_range));
        for (size_t i = 0; i < (buf->w) * (buf->h); i++) {
                fprintf(fp, "%hhu ", buf->data[i].r);
                fprintf(fp, "%hhu ", buf->data[i].g);
                fprintf(fp, "%hhu ", buf->data[i].b);
        }

        /* Unfortunatelly, generated p3 file has trailing space */
}

static void
writeP6(FILE *fp, struct PPM_Image_Buffer *buf)
{
        fprintf(fp, "\n%u %u\n%hu\n", buf->w, buf->h, (buf->component_range));
        for (size_t i = 0; i < (buf->w) * (buf->h); i++) {
                fprintf(fp, "%c", buf->data[i].r);
                fprintf(fp, "%c", buf->data[i].g);
                fprintf(fp, "%c", buf->data[i].b);
        }
}

int
write_ppm_color_bitmap(char *filename, struct PPM_Image_Buffer *buf)
{
        FILE *fp = fopen(filename, "w");
        if (!fp) {
                perror("Unable to create file");
                exit(-1);
        }
        fputs(ppm_id, fp);                      /* Put ppm identifier from 
                                                 * read buffer at line 1
                                                 */

                                                /* Put \n width and height at 
                                                 * line 2 from buffer and \n
                                                 */
        if (strcmp(ppm_id, "P3") == 0)
                writeP3(fp, buf);
        else
                writeP6(fp, buf);
        fclose(fp);
        return 0;
}

void
filter_color_component(struct PPM_Image_Buffer *buf, uint32_t rgb_mask)
{
        union pixelUnion mod;
        for (size_t i = 0; i < (buf->w) * (buf->h); i++) {
                mod.pixel.r = buf->data[i].r;
                mod.pixel.g = buf->data[i].g;
                mod.pixel.b = buf->data[i].b;

                mod.manipulatePixel &= rgb_mask;

                buf->data[i].r = mod.pixel.r;
                buf->data[i].g = mod.pixel.g;
                buf->data[i].b = mod.pixel.b;
                /* Poneje manipulatePixel ot uniona ne e ukazatel,
                 * trqbva nanovo da se prisvoqt stoinostite */
        }
}

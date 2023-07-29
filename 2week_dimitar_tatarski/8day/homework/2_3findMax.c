#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>

typedef struct point {
        double x;
        double y;
        double z;
} point;

typedef struct human {
        double weight_kg;
        uint16_t height_cm;
} human;

int cmpUint64_t(const void *first, const void *second);
int cmp3dPointRadVectorLen(const void *first, const void *second);
int cmpHumanBmi(const void *first, const void *second);
int cmpFloatCountOfOneBits(const void *first, const void *second);
void *findMax(void* arr, size_t n, size_t elem_s, int (*cmp)(const void*, const void*));

void *
findMax(
        void *arr,
        size_t n,
        size_t elem_s,
        int (*cmp)(const void *, const void *)
        )
{
        size_t max_i = 0;
        for (size_t i = 0; i < n; i++) {
                if (cmp( (char*)arr+i*elem_s, (char*)arr+max_i*elem_s) == 1)
                        max_i = i;
        }
        return (char *) arr + max_i * elem_s;
}

int
cmpUint64_t(const void *first, const void *second)
{
        if (*((uint64_t *) first) > *((uint64_t *) second))
                return 1;
        else if (*((uint64_t *) first) < *((uint64_t*) second))
                return -1;
        return 0;
}

int
cmp3dPointRadVectorLen(const void *first, const void *second)
{
        double vector1 = sqrt(
                ((point *)first)->x * ((point *)first)->x +
                ((point *)first)->y * ((point *)first)->y +
                ((point *)first)->z * ((point *)first)->z
        );
        double vector2 = sqrt(
                ((point *)second)->x * ((point *)second)->x +
                ((point *)second)->y * ((point *)second)->y +
                ((point *)second)->z * ((point *)second)->z
        );
        if (vector1 > vector2)
                return 1;
        else if (vector1 < vector2)
                return -1;
        return 0;
}

int
cmpHumanBmi(const void *first, const void *second)
{
        double bmi1, bmi2;
        double meters1, meters2;

        meters1 = (((human *)first)->height_cm)/100;
        meters2 = (((human *)second)->height_cm)/100;

        bmi1 = ((human *)first)->weight_kg / (meters1 * meters1);
        bmi2 = ((human *)second)->weight_kg / (meters2 * meters2);
        /* Round bracket hE11 ^^ =] */

        if (bmi1 > bmi2)
                return 1;
        else if (bmi1 < bmi2)
                return -1;
        return 0;
}

int
cmpFloatCountOfOneBits(const void *first, const void *second)
{
        uint32_t i1, i2;
        uint8_t count1 = 0, count2 = 0;
        memcpy(&i1, first, sizeof(float));
        memcpy(&i2, second, sizeof(float));
        for (size_t i = 0; i < sizeof(float)*8-1; i++) {
                if (i1 & (1UL << i))
                        count1++;
                if (i2 & (1UL << i))
                        count2++;
        }
        if (count1 > count2)
                return 1;
        if (count1 < count2)
                return -1;
        return 0;
}

int
main()
{
        uint64_t arr[] = {1, 2, 3, 4, 5, 6, 99, 1, 9};
        uint64_t *maxuint64 = findMax(
                        arr,
                        sizeof(arr)/sizeof(uint64_t),
                        sizeof(uint64_t),
                        cmpUint64_t
        );
        printf("%lu\n", *maxuint64);
/*----------------------------------------------------------*/
        point points[] = {
                        {-1, -1, -1}, /* {x, y, z} */
                        {-3, -3, -3},
                        {0, 0, 0}
        };
        point *maxdouble = findMax(
                        points,
                        sizeof(points)/sizeof(point),
                        sizeof(point),
                        cmp3dPointRadVectorLen
       );
        printf("%.2lf, %.2lf, %.2lf\n", maxdouble->x, maxdouble->y, maxdouble->z);
/*----------------------------------------------------------*/
        human humans[] = {
                        {.weight_kg = 101.5, .height_cm = 120},
                        {.weight_kg = 40.33, .height_cm = 220}
        };
        human *maxdoubleBmi = findMax(
                        humans,
                        sizeof(humans)/sizeof(human),
                        sizeof(human),
                        cmpHumanBmi
       );
        printf("%.2lf, %u\n", maxdoubleBmi->weight_kg, maxdoubleBmi->height_cm);
/*----------------------------------------------------------*/
        float floats[] = {-1.999999, -1.5, -1.75};
        float *maxfloatOnes = findMax(
                        floats,
                        sizeof(floats)/sizeof(float),
                        sizeof(float),
                        cmpFloatCountOfOneBits
        );
        printf("%f\n", *maxfloatOnes);
        return 0;
}

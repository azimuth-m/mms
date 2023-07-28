#include <stdio.h>

typedef struct float_comp {
        unsigned int mantissa : 23;
        unsigned int exponent :  8;
        unsigned int sign     :  1;
} float_comp;

typedef union F {
        float f;
        float_comp c;
} F;

int
main()
{
        F f1;
        scanf("%f", &(f1.f));
        printf("\nSign:    %b\nExponent: %b\nMantissa:         %b\n", f1.c.sign, f1.c.exponent, f1.c.mantissa);
        return 0;
}

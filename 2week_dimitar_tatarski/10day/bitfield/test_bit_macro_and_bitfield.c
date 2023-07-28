#include <stdio.h>

#define CHECK_BIT(a, i) (!!(a&(1ULL<<i)))

typedef struct C {
        unsigned int b7 : 1;
        unsigned int b6 : 1;
        unsigned int b5 : 1;
        unsigned int b4 : 1;
        unsigned int b3 : 1;
        unsigned int b2 : 1;
        unsigned int b1 : 1;
        unsigned int b0 : 1;
} char_bits;

typedef union c {
        char c;
        char_bits bits;
} C;

int
main()
{
        /* Test with macro */
        signed char c = -7;
        for (size_t i = 8; i > 0; i--) {
                printf("%u", CHECK_BIT(c, (i-1)));
        }

        printf("\n");

        /* Test with bitfield */
        C c1;
        c1.c = -7;
        printf("%u", c1.bits.b0);
        printf("%u", c1.bits.b1);
        printf("%u", c1.bits.b2);
        printf("%u", c1.bits.b3);
        printf("%u", c1.bits.b4);
        printf("%u", c1.bits.b5);
        printf("%u", c1.bits.b6);
        printf("%u", c1.bits.b7);
        return 0;
}

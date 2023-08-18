#include <stdio.h>
#include <inttypes.h>

struct double_comp {
        uint64_t mantissa : 52;
        uint64_t exponent : 11;
        uint64_t sign     :  1;
};

union D {
        double d;
        struct double_comp c;
};

void
printDoubleBits(union D d)
{
         printf("\nSign:    %lb\nExponent: %lb\nMantissa:           %lb\n", d.c.sign, d.c.exponent, d.c.mantissa);
}

/* Da, moje, i e preporuchitelno bitovete 
 * da se printirat sus bitTest fx
 * i nqkakuv cikul, ili nqkakvi drugi sposobi,
 * NO %b / %lb prosto e po burzo i udoblno 
 * vupreki che e "deprecated"
 */

int
main()
{
        union D d1;
        d1.d = -1.999999999999999;
        printDoubleBits(d1);
        return 0;
}

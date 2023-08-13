#include <stdio.h>
#include <inttypes.h>
#define DEVIATION 0.000001F

union manX {
        uint64_t tempx;
        double d;
};

double
cbrt(double x)
{
        /* Neshto se zatrudnqva sus stoinosti mejdu 0 i 1, kakto i mejdu -1 i 0
         * ne mi se zanimava */
        union manX mod;
        mod.d = x;
        unsigned char isNegative = !!(mod.tempx & (1ULL << (sizeof(uint64_t)*8 - 1)));
        mod.tempx &= ~(1ULL << (sizeof(uint64_t)*8 - 1));
        x = mod.d;

        double min = 0;
        double max = x;

        while (1) {
                double avg = (min + max)/2;

                if ( ((avg*avg*avg - x) > -DEVIATION) && ((avg*avg*avg - x) < DEVIATION)) {
                        if (isNegative)
                                return -avg;
                        else
                                return avg;
                }
                if (avg*avg*avg > x)
                        max = avg;
                else
                        min = avg;
        }

}

int
main()
{
        double a = 0;
        double b = 0;

        scanf("%lf", &a);
        b = cbrt(a);
        printf("%lf", b);
        return 0;
}

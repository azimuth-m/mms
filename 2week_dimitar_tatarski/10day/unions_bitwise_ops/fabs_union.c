#include <stdio.h>
#include <inttypes.h>

union data {
        double    d;
        uint64_t ui;
};

double
fabs_union(double y)
{
        union data d1;
        d1.d = y;
        d1.ui = d1.ui & ~(1ULL << 63);
        return d1.d;
}

int
main()
{
        double d;
        scanf("%lf", &d);
        printf("%lf\n", d);
        printf("%lf\n", fabs_union(d));
        return 5;
}

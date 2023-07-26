#include <stdio.h>
#include <stdint.h>

float
my_fabs(float a)
{
        uint32_t i;
        float f;

        f = a;
        i  = *(uint32_t *) &f; // Evil bit hack :D
        i &= ~(1UL << 31);
        f  = *(float *) &i;
        return f;
}

int
my_abs(int64_t a)
{
        int sign_bit_value = !!(a & (1ULL << 63));
        return (a * !sign_bit_value + ~(a-1)*sign_bit_value);
}
int
main()
{
        float f = -3.1234567;
        int i = -1;
        printf("%f\n", f);
        printf("%f\n", my_fabs(f));
        printf("%d\n", i);
        printf("%d\n", my_abs(i));
}

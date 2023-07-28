#include <stdio.h>
#define DEVIATION 0.0001F

double
cbrt(double x)
{
        double min = -(x - DEVIATION);
        double max =  (x - DEVIATION);
        double avg =  (min + max) / 2;


        while (min <= max) {
                if ((avg*avg*avg - x < DEVIATION) && (avg*avg*avg-x > - DEVIATION)) {
                        return avg; 
                } else if (avg*avg*avg - x > DEVIATION) {
                        max = avg - DEVIATION;
                } else if (avg*avg*avg - x < DEVIATION) {
                        min = avg + DEVIATION;
                }
        }

}

int
main()
{
        double a = 0;
        double b = 0;

        scanf("%lf", &a);
        b = cbrt(a);
        printf("%lf", a);
        return 0;
}

#include <stdio.h>
#include <math.h>

int
calcTriangle(double a, double b, double c,
             double *area, double *perimeter
            )
{
        if (a+b <= c || a+c <= b || b+c <= a || !a || !b || !c)
                return -1;

        double sP = (a + b + c) / 2;
        *perimeter = a + b + c;
        *area = sqrt(sP*(sP-a)*(sP-b)*(sP-c));
        return 0;
}

int
main()
{
        double a, b, c, area=-1, perimeter=-1;

        while (scanf("%lf %lf %lf", &a, &b, &c) == 3) {
                if (calcTriangle(a, b, c, &area, &perimeter)) {
                        printf("Invalid input\n");
                } else {
                printf("\na = %lf\nb = %lf\nc = %lf\n\nP = %lf\nArea = %lf\n\n",
                            a,       b,       c,       perimeter,  area);
                }
        }
        return 0;
}

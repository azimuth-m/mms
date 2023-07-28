#include <stdio.h>
#include <stdlib.h>
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
main(int argc, char *argv[])
{
        double a, b, c, area=-1, perimeter=-1;
        if (argc != 4) {
                fprintf(stderr, "Invalid command line argument\n");
                return EXIT_FAILURE;
        }
        if (sscanf(argv[1], "%lf", &a) == 0 || sscanf(argv[2], "%lf", &b) == 0 || sscanf(argv[3], "%lf", &c) == 0) {
                fprintf(stderr, "Invalid command line argument\n");
                return EXIT_FAILURE;
        }

                if (calcTriangle(a, b, c, &area, &perimeter)) {
                        printf("Invalid input\n");
                } else {
                printf("a = %lf\nb = %lf\nc = %lf\n\nP = %lf\nArea = %lf",
                            a,       b,       c,       perimeter,  area);
                } 
        return 0;
}

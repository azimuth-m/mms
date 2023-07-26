#include <stdio.h>
#define PI 3.141592

int
cylinder(double r, double h, double *V, double *S)
{
        if (r < 1 || h < 1 ) {
                printf("\nInvalid data\n");
                return -1;
        }
        *S = 2 * PI * r * (r + h);
        *V = PI * r * r *h;
        return 0;
}

int
main(void)
{
        double r; 
        double h;
        double V, S;
        fflush(stdin);
        scanf("%f %f", &r, &h);

        printf("\n%f, %f\n", r, h);
        cylinder(r, h, &V, &S);
        printf("\nV = %f, S = %f\n", V, S);
        return 0;
}

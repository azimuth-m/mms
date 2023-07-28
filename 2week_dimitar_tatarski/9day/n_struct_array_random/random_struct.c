#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct point {
        double x;
        double y;
};

double
distance2points(struct point a, struct point b)
{
        return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)); 
}

int
main(int argc, char *argv[])
{
        srand(time(0));
        unsigned N = 0;

        if (argc != 2) {
                fprintf(stderr, "Invalid number of arguments");
                return EXIT_FAILURE;
        }

        if (sscanf(argv[1], "%u", &N) != 1) {
                fprintf(stderr, "Invalid number of arguments");
                return EXIT_FAILURE;
        }

        printf("%u\n", N);
        //struct point *p_arr = malloc(sizeof(struct point) * N);

        /*      Poneje N e command line argument, toi e izvesten @ runtime,
         *      moje da se zadei pamet statichno
         */      

        struct point p_arr[N];
        for (size_t i = 0; i < N; i++) {
                p_arr[i].x = (double)(rand()%1000)/1000 + 0.001;
                p_arr[i].y = (double)(rand()%1000)/1000 + 0.001;
        }
        for (size_t i = 0; i < N; i++) {
                printf("p%lu(%.3lf, %.3lf)\n",
                          i, p_arr[i].x, p_arr[i].y);
        }
        printf("\n");
        for (size_t i = 0; i < N; i++) {
                for (size_t j = i+1; j < N; j++) {
                        printf("Distance between p%lu and p%lu = ", i, j); 
                        printf("%lf\n", distance2points(p_arr[i], p_arr[j]));
                }
        }
        //free(p_arr);
        return 0;
}

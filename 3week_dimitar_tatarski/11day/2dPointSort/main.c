#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

struct Point {
        double x;
        double y;
};

void
printArr(const struct Point *arr, size_t n)
{
        for (size_t i = 0; i < n; i++)
                printf("(%.3lf, %.3lf)\n", arr[i].x, arr[i].y);
        printf("\n");
}

int
cmpPointX(const void *first, const void *second)
{
        return (((struct Point *)first)->x - ((struct Point *)second)->x)*1000;
}

int
main()
{
        srand(time(NULL));
        struct Point *parr = malloc(N * sizeof(struct Point));

        for(size_t i = 0 ; i < N; i++) {
                (parr+i)->x = (double)(-1000 + rand()%2001)/1000; /* in range [-1.000, 1.000]*/
                (parr+i)->y = (double)(-1000 + rand()%2001)/1000; /* in range [-1.000, 1.000]*/
        }

        printArr(parr, N);
        qsort(parr, N, sizeof(struct Point), cmpPointX);
        printArr(parr, N);
        return 0;
}

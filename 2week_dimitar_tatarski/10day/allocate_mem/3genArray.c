#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

void
initElem(void *elem)
{
        *((int *) elem) = 17;
}

void
init_double_Elem(void *elem)
{
        *((double *) elem) = (rand()%1000000)/1000;
}

void *
genArray(void (*init_elem)(void *), size_t elem_c, size_t elem_size)
{
        void *arr = malloc(elem_c * elem_size);
        for (size_t i = 0; i < elem_c; i++) {
                init_elem((char *)arr + i*elem_size);
        }
        return arr;
}

int
main()
{
        int *arr0 = genArray(initElem, 7, sizeof(int));
        double *arr1 = genArray(init_double_Elem, 7, sizeof(double));

        for (size_t i = 0; i < 7; i++) {
                printf("%d ", arr0[i]);
        }

        printf("\n");

        for (size_t i = 0; i < 7; i++) {
                printf("%.1lf ", arr1[i]);
        }
        printf("\n");

        free(arr0);
        free(arr1);
        return 0;
}

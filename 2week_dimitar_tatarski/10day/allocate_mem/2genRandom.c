#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>

int *
genRandom(size_t elem_c)
{
        int *gen_arr = malloc(sizeof(int) * elem_c);
        for (size_t i = 0; i < elem_c; i++) {
                gen_arr[i] = -100 + (rand() % (100 + 100 + 1));
                //gen in range [-100:100]
        }

        return gen_arr;
}

int
main()
{
        srand(time(0));
        int *arr = genRandom(10);
        for (size_t i = 0; i < 10; i++) {
                printf("%d ", arr[i]);
        }
        free(arr);
        return 0;
}

#include <stdio.h>

void
printRow(int (*arr)[4]) {
        for (size_t i = 0; i < 4; i++) {
                printf("%d ", (*arr)[i]);
        }
}

void print2dArr(int arr[3][4]) {
        for (size_t i = 0; i < 3; i++) {
                printRow(arr + i);
                printf("\n");
        }

}
int
main()
{
//      int arr[7];
//
//        int (*p_to_arr)[7] = &arr; /* Ukazatel KUM sedemte lementa na masiv */
//        /* int *p = &arr;             Ukazatel kum purviq element na masiv */
//        /*        ^^   Array to pointer decay */

        int arr[3][4] = {
                {1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12}
        };

        int *p = arr[0];

        for (size_t i = 0; i < 3*4; i++) {
                printf("%d ", p[i]);
        }

        printf("\n");
        print2dArr(arr);
        return 0;
}

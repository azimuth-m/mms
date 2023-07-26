#include <stdio.h>

int arr[3] = {1, 2, 3};

void
swap(int *a, int *b)
{
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
}

void
permutate(int begin, int end) 
{
        if (begin == end) {
                for (int i = 0; i < end; i++) {
                        printf("%d ", arr[i]);
                }
                printf("\n");
        }

        for (int i = begin; i < end; i++) {
                swap(arr + begin, arr + i);
                permutate(begin + 1, end);
                swap(arr + begin, arr + i);
        }
}


int
main()
{
        permutate(0, 3);
        return 0;
}

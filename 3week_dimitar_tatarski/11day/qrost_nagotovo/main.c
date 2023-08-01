#include <stdio.h>
#include <stdlib.h>

int
cmpInts(const void *first, const void *second)
{
        return (*((int *) first) - *((int *) second))
}

int
main()
{
        int arr[] = {-1, 2, 65, 0, 11, 22, -40, 9};

        qsort(arr, sizeof(arr)/sizeof(int), sizeof(int), cmpInts);

        for (int i = 0 ; i < sizeof(arr)/sizeof(int); i++)
                printf("%d ", arr[i]);
        return 0;
}

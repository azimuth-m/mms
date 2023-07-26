#include <stdio.h>

void
swap(int *a, int *b)
{
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
}

void
perm(int *arr, int start, int end)
{
        int i;
        if (start == end) {
                for (int j = 0; j < end; j++)
                        printf("%d", arr[j]);
                printf("\n");
        } else {
                for (i = 0; i < end; i++) {
                        swap((arr+start), (arr+end));
                        perm(arr, start+1, end);
                        swap((arr+start), (arr+end));
                }
        }
}

int
main()
{
        int arr[] = {1, 2, 3, 4, 5};
        perm(arr, 0, 5);
        return 0;
}

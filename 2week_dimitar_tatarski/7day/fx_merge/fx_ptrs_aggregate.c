#include <stdio.h>
#include <stdint.h>

/* arr1 i arr2 sa sortirani 
 * slivat se i rezultat se zapisva v dest
 */
void
merge(int *arr1, int n1, int *arr2, int n2, int *dest)
{
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
                if (arr1[i] < arr2[j]) {
                        *(dest++) = arr1[i];
                        i++;
                } else {
                        *(dest++) = arr2[j];
                        j++;
                }
        }
        if (i < n1) {
                for (size_t o = i; o < n1; o++) 
                        *(dest++) = arr1[i];
        } else {
                for (size_t o = j; o < n2; o++) 
                        *(dest++) = arr1[i];
        }
}

int
main()
{
        int arr[5]={1, 3, 5, 7, 9};
        int arr1[5]={0, 2, 4, 6, 8};
        int dest[10];
        merge(arr, 5, arr1, 5, dest);
        for(size_t i = 0; i < 10; i++)
                printf("%d", dest[i]);
        /* (((((15+1)+2)+3)+4)+5) */
        return 0;
}

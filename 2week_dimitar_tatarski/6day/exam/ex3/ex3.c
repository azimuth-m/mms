#include <stdio.h>
#include <stdlib.h>

void
subseq(int arr[], int n, int dest[], int *new_n)
{
        int cur_start = 0,
            max_start = 0,
            max_lenght = 1;

        for (size_t i = 0; i < n; i++) {
                if (arr[i-1] < arr[i]) {
                        int cur_lenght = i - cur_start;

                        if (cur_lenght > max_lenght) {
                                max_lenght = cur_lenght;
                                max_start = cur_start;
                        }
                        cur_start = i;
                }
        }
int cur_lenght = n - cur_start;
        if (cur_lenght > max_lenght) {
                max_lenght = cur_lenght;
                max_start = cur_start;
        }
*new_n = max_lenght;
        for (size_t i = max_start; i < max_lenght; i++)
                *(dest++) = arr[max_start + i];
}

int
main()
{
        int n;
        int *arr;
        int *dest;
        int new_n;

        printf("Expected size: ");
        scanf("%d", &n);
        
        arr = (int *) malloc(n * sizeof(int));
        
        for(int i = 0; i < n; i++) {
                printf("Expected arr[%d] = ", i); 
                scanf("%d", &arr[i]);
        }

        /* Print array */
        for(int i = 0; i < n; i++) {
                printf("arr[%d] = %d\n", i, arr[i]); 
        }
        
        free(arr);

        return 0;
}

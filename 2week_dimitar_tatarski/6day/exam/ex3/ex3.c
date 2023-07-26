#include <stdio.h>
#include <stdlib.h>

void
subseq(int arr[], int n, int dest[], int *new_n)
{
        int start_index = 0;
        int end_index = 0;
        int count = 0;

        /* ... */
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

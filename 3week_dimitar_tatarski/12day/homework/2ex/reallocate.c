#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

void
print_arr(float *arr, int n)
{
        for (int i = 0; i < n; i++)
                printf("%.1f\n", arr[i]);
}

int
main()
{
        srand(time(0));
        float *arr = NULL;

        /* Create array with n elem */
        int n = 0;
        printf("Enter unsigned int n: ");
        scanf("%d", &n);

        arr = malloc(sizeof(float) * n);
        if (arr == NULL) {
                perror("Unable to allocate");
                exit(errno);
        }
        for (int i = 0; i < n; i++)
                arr[i] = ((float)(rand() % 11))/10;
        print_arr(arr, n);

        /* Extend array with m elem */
        int m = 0;
        printf("Enter unsigned int m: ");
        scanf("%d", &m);

        arr = realloc(arr, sizeof(float) * (m + n));
        if (arr == NULL) {
                perror("Unable to allocate");
                exit(errno);
        }
        for (int i = n; i < (m + n); i++)
                arr[i] = ((float)(10 + rand() % 11))/10;
        print_arr(arr, (n+m));

        /* Extend array with p elem */
        int p = 0;
        printf("Enter unsigned int m: ");
        scanf("%d", &p);

        arr = realloc(arr, sizeof(float) * (m + n + p));
        if (arr == NULL) {
                perror("Unable to allocate");
                exit(errno);
        }
        for (int i = m; i < (m + n + p); i++)
                arr[i] = ((float)(20 + rand() % 11))/10;
        print_arr(arr, (n+m+p));

        free(arr);


        return 0;
}

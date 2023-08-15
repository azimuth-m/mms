#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define READ_INT_COUNT 10000

int
main()
{
        int *curNumArray = malloc(sizeof(int) * READ_INT_COUNT);
        unsigned long long sum = 0;
        int num_read;
        do {
                num_read = read(STDIN_FILENO, curNumArray, sizeof(int) * READ_INT_COUNT);
                for (size_t i = 0; i < num_read / sizeof(int); i++)
                        sum += curNumArray[i];
        } while (num_read > 0);
        free(curNumArray);
        printf("%lld", sum);
        return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/stat.h>
#include <errno.h>

#define K 10
int file_size;
int *numbers;
unsigned long long sum = 0;
pthread_mutex_t lock;

void *
worker(void *arg)
{
        int th_indx = *((int *) arg);
        unsigned long long localSum = 0;
        printf("Staring thread %d...\n", th_indx);

        for (int i = 0; i < (file_size/K)/sizeof(int); i++) {
                localSum += numbers[i + th_indx * (file_size/K)/sizeof(int)];
        }

        pthread_mutex_lock(&lock);
        sum += localSum;
        pthread_mutex_unlock(&lock);

        printf("\t\t\tClosing thread %d...\n", th_indx);
        return NULL;
}

int
main(int argc, char *argv[])
{
        pthread_mutex_init(&lock, NULL);
        pthread_t handle[K];
        int thread_id[K];

        /* 2. Open file for reading and 1. check file size */
        struct stat f1_info;
        stat(argv[1], &f1_info);
        FILE *f1 = fopen(argv[1], "r");
        file_size = f1_info.st_size;
        numbers = malloc(file_size);
        fread(numbers, sizeof(int), file_size, f1);
        fclose(f1);

        for (int i = 0; i < K; i++) {
                //int *a = malloc(sizeof(int));
                //*a = i;
                thread_id[i] = i;
                if (pthread_create(handle + i, NULL, worker, thread_id + i) == -1 ) {
                        perror("Could not create thread");
                        exit(errno);
                }
        }

        for (int i = 0; i < K; i++)
                pthread_join(handle[i], NULL);
        pthread_mutex_destroy(&lock);
        free(numbers);
        printf("Sum: %d\n", sum);

        return 0;
}

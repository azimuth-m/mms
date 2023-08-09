#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h>
#include <errno.h>
#include <semaphore.h>

#define THREADS_NUM 7

sem_t sem1;

void *
myTask1(void *arg)
{
        sem_wait(&sem1);
        printf("Thread No: %d\n", *((int *) arg)); 
        sem_post(&sem1);
        return NULL;
}

int
main()
{
        pthread_t tr[THREADS_NUM];
        sem_init(&sem1, 0, 1);
        for (int i = 0; i < THREADS_NUM; i++) {
/*sus castvane na adresa na i kum void ne raboti. sus int *a = i; sushto ne raboti. */
                int *a = malloc(sizeof(int));
                *a = i;

                if (pthread_create(tr + i, NULL, myTask1, a) < 0)
                        exit(errno);
        }

        for (size_t i = 0; i < THREADS_NUM; i++) {
                if (pthread_join(tr[i], NULL) < 0)
                        exit(errno);
        }

        sem_destroy(&sem1);
        return 0;
}

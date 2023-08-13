#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#define THREAD_NUM 16

sem_t semaphorec;

void *
routine(void *arg)
{
        int id = *(int *)arg;

        printf("[%2d] waiting...\n", id);
        sem_wait(&semaphorec); /*  <-- Dec semaphore   */
        printf("    [%2d] log IN SUCCESS!\n", id);
        sleep(1);
        sem_post(&semaphorec); /*  <-- Inc semaphore   */
        printf("        [%2d] log OUT!\n", id);
        free(arg); /*  <-- prevent a mem leak */
        return NULL;
}

int
main()
{
        sem_init(&semaphorec, 0, 32);
        pthread_t user[THREAD_NUM];

/* Create threads (users), NON-WAITING*/
        for (int i = 0; i< THREAD_NUM; i++) {
                int *a = malloc(sizeof(int));
                *a = i;
                if (pthread_create(user + i, NULL, routine, a) < 0) {
                        perror("Cannot create thread");
                        exit(errno);
                }
        }

/* Wait for threads to finish, before return 0 */
        for (size_t i = 0; i< THREAD_NUM; i++) {
                if (pthread_join(user[i], NULL) < 0) {
                        perror("Cannot join thread");
                        exit(errno);
                }
        }
        sem_destroy(&semaphorec);

        return 0;
}

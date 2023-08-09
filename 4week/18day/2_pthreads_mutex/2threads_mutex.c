#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

int cnt;
pthread_mutex_t lock1;

void *
myTask1()
{
        for (size_t i = 0; i < 1000000; i++) {
                pthread_mutex_lock(&lock1);
                cnt++;
                pthread_mutex_unlock(&lock1);
        }
        return NULL;
}

int
main()
{
        pthread_t tr1, tr2;
        pthread_mutex_init(&lock1, NULL);
        if (pthread_create(&tr1, NULL, &myTask1, NULL) < 0)
                exit(errno);
        if (pthread_create(&tr2, NULL, &myTask1, NULL) < 0)
                exit(errno);

        if (pthread_join(tr1, NULL) < 0) /* Izchakvane na nishka tr1 */
                exit(errno);
        if (pthread_join(tr2, NULL) < 0) /* Izchakvane na nishka tr2 */
                exit(errno);

        pthread_mutex_destroy(&lock1);
        printf("Count: %d\n", cnt);
        return 0;
}

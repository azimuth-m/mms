#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

int cnt;

void *
myTask1()
{
        for (size_t i = 0; i < 100000; i++)
                cnt++;
        /* Pri chisla > 100, moje dase poqvqt problemi. Ne se udvoqva kakto bi se ochakvalo */

        return NULL;
}

void *
myTask2()
{
        for (size_t i = 0; i < 100000; i++)
                cnt++;
        /* Nujni sa sinhronizacionni primitivi (atomizirane), za da ne se narushi sustoqtelnostta
         * na dannite, ot reda na operaciite
         */

        return NULL;
}

int
main()
{
        pthread_t tr1, tr2;
        if (pthread_create(&tr1, NULL, &myTask1, NULL) < 0)
                exit(errno);
        if (pthread_create(&tr2, NULL, &myTask1, NULL) < 0)
                exit(errno);

        if (pthread_join(tr1, NULL) < 0) /* Izchakvane na nishka tr1 */
                exit(errno);
        if (pthread_join(tr2, NULL) < 0) /* Izchakvane na nishka tr2 */
                exit(errno);

        printf("Count: %d\n", cnt);
        return 0;
}

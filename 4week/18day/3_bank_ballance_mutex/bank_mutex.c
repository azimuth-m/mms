#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

#define NUM_THREADS 70000
#define INIT_BALANCE 1000

struct Account {
        int balance;
};

struct Account a;
pthread_mutex_t lock1;

void *
withdraw(void *amount) {
        pthread_mutex_lock(&lock1);
        a.balance -= *((int *)amount);
        pthread_mutex_unlock(&lock1);
        return NULL;
}
void *
deposit(void *amount) {
        pthread_mutex_lock(&lock1);
        a.balance += *((int *)amount);
        pthread_mutex_unlock(&lock1);
        return NULL;
}
void
printBal() {
        printf("Current balance: %d\n", a.balance);
}
int
main()
{
        int WITHDRAW = 100; /* 1, 3, 5 withdraw 100 = 300 */
        int DEPOSIT = 200; /* 0, 2, 4, 6 threads deposit 200 = 800 */

        a.balance = INIT_BALANCE; /* Initial ballance */
        printBal();

        /* Init mutex */
        pthread_mutex_init(&lock1, NULL);

        /* Create & init threads */
        pthread_t threads[NUM_THREADS];

        for (size_t i = 0; i < NUM_THREADS; i++) {
                if (i%2 == 0) {
                        pthread_create(threads + i, NULL, deposit, ((void *) &DEPOSIT));
                } else {
                        pthread_create(threads + i, NULL, withdraw, ((void *) &WITHDRAW));
                }
        }

        /* Wait for all threads to complete operation, before exiting main */
        for (size_t i = 0; i < NUM_THREADS; i++)
                pthread_join(threads[i], NULL);

        /* Destroy mutex */
        pthread_mutex_destroy(&lock1);
        printBal();

        return 0;
}

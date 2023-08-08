#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main()
{

/*
        int pid;
        pid = fork();
        if (pid == 0)
                printf("Child process PID: %d\n",pid);
        else
                printf("Parent process PID: %d\n", pid);
*/

/*
        fork();
        fork();
        printf("One\n");
*/

        int pid = fork();

        printf("\nPID 1st fork: %d\n", pid);

        /* In main process */
        if (pid != 0) {
                int pid2 = fork();
                printf("\nPID2 2nd fork: %d\n", pid2);
        }
        /* In child process */
        else {
                printf("\nPID in else : %d\n", pid);
        }

        return 0;
}

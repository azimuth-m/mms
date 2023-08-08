#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int
main()
{
        pid_t pid = fork(); /* int */

        if (pid == 0) {
                /* Child */
                printf("Waiting 3 seconds...\n");
                sleep(3);
                printf("Child's parent PID:  %d\n", getppid());
                printf("Child PID:           %d\n", getpid());
        }
        /* HEre, since the parent is waiting for the child process, the child does not become an orphan */
        else {
                /* Parent */
                printf("Parent's Parent PID: %d\n", getppid());
                printf("Parent PID:          %d\n", getpid());
                wait(NULL);
        }
        return 0;
}

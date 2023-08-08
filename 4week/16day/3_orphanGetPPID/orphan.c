#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


/* Pechat na chisla ot 1 do 10.
 * Ako sme v parent process [1, 5]
 * Ako sme v child [6, 10]
 */

int
main()
{
        int pid = fork();

        if (pid == 0) {
                /* Child */
                printf("\nWaiting 3 seconds...\n");
                sleep(3);
                printf("\nChild's parent PID:  %d\n", getppid());
                printf("Child PID:           %d\n", getpid());
        }
        /* If the main process ends befor it child finishes, in order not to kill the child, the child is asigned a new paren process (in my case PID 1 ( /sbin/init) */
        else {
                /* Parent */
                printf("Parent's Parent PID: %d\n", getppid());
                printf("Parent PID:          %d\n", getpid());
        }
        return 0;
}

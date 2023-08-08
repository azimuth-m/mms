#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/wait.h>

/* - Make 3 processes: 1 Parent, 2 child.
 * - Parent sends data to Child 1.
 * - Child 1 multiplies by 3 and sends the data to Child 2
 * - Child 2 check value. if even, square it, if odd, divide by two;
 *   Then send to parent
 * - Parent prints result
 */

int
main()
{
        int fd[3][2]; /* 3 pipes (descriptors) */
        pipe(fd);

        pid_t pid;
        pid = fork();

        if(pid == 0) {
/* Child 1 */
                close(fd[0][1]); /* Close pipe 0's write */
                close(fd[1][0]); /* Close pipe 1's read  */
                close(fd[2][0]); /* Close pipe 2's read  */
                close(fd[2][1]); /* Close pipe 2's write */
                
                int b;
                while (read(fd[0][0], &b, sizeof(b)) < sizeof(b));
                /* Wait to read atlest 4 bytes */
                /* napulno neefektivno i boroken ^^ */
                b *= 3;
                close(fd[0][0]); /* CLose pipe 0's read */
                write(fd[1][1], &b, sizeof(b));
                close(fd[1][1]); /* CLose pipe 0's read */

                printf("\n%d\n", b);

        }
        else if(pid) {
/* Parent isolated from child 1*/
                close(fd[2][1]); /* Close pipe 2's write */
                close(fd[1][1]); /* Close pipe 1's write  */
                close(fd[1][0]); /* Close pipe 1's read  */
                close(fd[0][0]); /* Close pipe 0's read */
                pid_t pid2;
                pid2 = fork();
                if (pid2 == 0) {
/* Child 2 */
                        close(fd[2][0]); /* Close pipe 2's read */
                        close(fd[1][1]); /* Close pipe 1's write  */
                        close(fd[0][0]); /* Close pipe 0's read  */
                        close(fd[0][1]); /* Close pipe 0's write */

                        /* close pipes after operation */
                } else if (pid2 == -1) {
                        exit(2);
                } else if (pid2) {
/* Parent isolated from child 2 and child 1 */
                        wait(); /* Wait for child 2 */
                }
                wait(); /* Wa it for child 1 */
        } else if (pid == -1) {
                /* check if fork1 successful */
                exit(1);
        }
        return 0;
}

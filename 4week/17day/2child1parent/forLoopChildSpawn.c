#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/wait.h>

#define ARRAYSIZE 10
/* - Make 3 processes: 1 Parent, 2 child.
 * - Parent sends data to Child 1.
 * - Child 1 multipleis data with 3 nad sends result to child 2 through pipe
 * - Child 2 checks for oddness, and mods based on in; Sends modded data to parent
 * - Parent prints result
 */

int pipe_fd_list[3][2]; /* 3 pipes (descriptors) */

void
childFun(int i)
{
        if (i == 0) {
                int buf;

                close(pipe_fd_list[0][1]);
                close(pipe_fd_list[1][0]);
                close(pipe_fd_list[2][0]);
                close(pipe_fd_list[2][1]);

                read(pipe_fd_list[0][0], &buf, sizeof(int));
                close(pipe_fd_list[0][0]);
                
                buf *= 3;

                /* Assuming 0 is even (it is not, but 0%2 == 0) */
                write(pipe_fd_list[1][1], &buf, sizeof(int));
                close(pipe_fd_list[1][1]);
        } else if (i == 1) {
                close(pipe_fd_list[0][0]);
                close(pipe_fd_list[0][1]);
                close(pipe_fd_list[1][1]);
                close(pipe_fd_list[2][0]);

                /* Read evenSum, from proc 1 */
                int localVar1;
                read(pipe_fd_list[1][0], &localVar1, sizeof(int));
                close(pipe_fd_list[1][0]);
                if (!localVar1%2)
                        localVar1 *= localVar1;
                else
                        localVar1 /= 2;

                write(pipe_fd_list[2][1], &localVar1, sizeof(int));
                close(pipe_fd_list[2][1]);
        }
}

int
main()
{
        pid_t pid;

        /* Generate random array in parent */
        int myValue = 7;

        /* Create 3 pipes */
        pipe(pipe_fd_list[0]);
        pipe(pipe_fd_list[1]);
        pipe(pipe_fd_list[2]);

        /* Create 2 children */
        for (int i = 0; i < 2; i++) {
                pid = fork();
                if (pid < 0) {
                        exit(-1);
                } else if (pid == 0) {
                        /* Child proc */
                        childFun(i);
                        return 0;
                }
        }
        close(pipe_fd_list[1][0]);
        close(pipe_fd_list[1][1]);
        close(pipe_fd_list[0][0]);
        close(pipe_fd_list[2][1]);

        write(pipe_fd_list[0][1], &myValue, sizeof(myValue));
        close(pipe_fd_list[0][1]);

        int result;
        /* Ne e nujen wait, poneje read-a na pipa blokira, dokato ne prochete pravilniq broi danni*/
        read(pipe_fd_list[2][0], &result, sizeof(int));
        close(pipe_fd_list[2][0]);

        printf("(parent) MOdded value: %d\n", result);
        
        return 0;
}

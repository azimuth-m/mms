#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/wait.h>

#define ARRAYSIZE 10
/* - Make 3 processes: 1 Parent, 2 child.
 * - Parent sends data to Child 1.
 * - Child 1 sums even nums and sends the data to Child 2
 * - Child 2 writes to pipe 2, the square of the sum, from pipe 1
 *   Then send to parent
 * - Parent prints result
 */

int pipe_fd_list[3][2]; /* 3 pipes (descriptors) */

void
childFun(int i)
{
        if (i == 0) {
                int buf[ARRAYSIZE];
                int evenSum = 0;

                /* Read first, then close, in case parent is not yet ready writing */
                read(pipe_fd_list[0][0], buf, sizeof(int) * ARRAYSIZE);
                close(pipe_fd_list[0][0]);

                /* Assuming 0 is even (it is not, but 0%2 == 0) */
                for (int i = 0; i < ARRAYSIZE; i += 2)
                        evenSum += buf[i];
                printf("Sum of even nums in array (child 0): %d\n", evenSum);
                write(pipe_fd_list[1][1], &evenSum, sizeof(int));
                close(pipe_fd_list[1][1]);
                } else if (i == 1) {

                /* Read evenSum, from proc 1 */
                int localVar1;
                read(pipe_fd_list[1][0], &localVar1, sizeof(int));
                close(pipe_fd_list[1][0]);
                localVar1 *= localVar1;
                write(pipe_fd_list[2][1], &localVar1, sizeof(int));
                close(pipe_fd_list[2][1]);
        }
}

int
main()
{
        pid_t pid;

        /* Generate random array in parent */
        int randInts[ARRAYSIZE];
        for (int i = 0; i < ARRAYSIZE; i++) {
                randInts[i] = i;
                printf("indx[%d] == %d\n", i, randInts[i]);
        }

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

        write(pipe_fd_list[0][1], &randInts, sizeof(int) * ARRAYSIZE);
        close(pipe_fd_list[0][1]);

        for (int i = 0; i < 3; i++)
                wait(NULL);

        int result;
        read(pipe_fd_list[2][0], &result, sizeof(int));
        close(pipe_fd_list[2][0]);

        printf("(parent) Square of even nums: %d\n", result);
        
        return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int
main()
{
        int pipe_fd[2]; /* fd[0] read; fd[1] write; */
        pipe(pipe_fd);

        pid_t pid = fork();

        if (pid == -1) {
                perror("Fork Error");
                exit(-1);
/* Child ================================================================== */
        } else if (pid == 0) {
                close(pipe_fd[0]);
                int n = rand()%10;
                for (int i = 0; i < n; i++) {
                        if (write(pipe_fd[1], &i, sizeof(n)) != sizeof(n))
                                perror("Write error");
                }
                close(pipe_fd[1]);
/* parent ================================================================= */
        } else {
                close(pipe_fd[1]);
                int res, numB;
                while ((numB = read(pipe_fd[0], &res, sizeof(res))) > 0)
                        printf("Res: %d\n", res);
                close(pipe_fd[0]);

        }

        return 0;
}

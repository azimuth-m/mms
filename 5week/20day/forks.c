#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int
main()
{
        pid_t pid = fork();
        if (pid == -1) {
                perror("Fork Error");
                exit(-1);
        } else if (pid == 0) {
                printf("Child\n");
                return -1;
        } else {
                int wstatus;
                pid_t child_pid = wait(&wstatus);
                printf("Parent\n");
                printf("Child PID: %d\n", child_pid);
                printf("Child wstatus: %d\n", wstatus);
                if (WIFEXITED(wstatus)) {
                        printf("Child exited normally\n");
                        printf("Child Exit code: %d\n", WEXITSTATUS(wstatus));
                } else
                        printf("Child did not exit normally\n");
        }

        return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#define K 3

void
childFun(int child_index)
{
        printf("Started child process with index %d: \n", child_index);
}

int
main()
{
        pid_t pid;
        int child_index;

        for (int i = 0; i < K; i++) {
                pid = fork();
                if(pid < 0) {
                        perror("Unable to create child proc");
                        exit(errno);
                } else if (pid == 0) {
                        //Child
                        childFun(i);
                }
                wait(NULL);
        }
        printf("Parent\n");
        return 0;
}

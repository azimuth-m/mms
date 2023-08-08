#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int
main()
{
        char string1[255];
        fgets(string1, 255, stdin);
        string1[strlen(string1) - 1] = '\0'; /* Remove carrige return */
/* Create FD array and pipe */
        int fd[2];
        pipe(fd);

/* Create a new process fork() */
        pid_t pid;
        pid = fork();

        if (pid == -1) {
                exit(1);
        } else if (pid == 0) {
                close(fd[0]); /* Close pipe for reading */
                write(fd[1], string1, strlen(string1));
                close(fd[1]); /* Close pipe for writing */
        } else {
                wait(NULL); /* Wait for child to write */
                close(fd[1]); /* Close pipe for writing */
                char string2[255];
                /* Read from fd[0] and write to local buffer string2 */
                if (read(fd[0], string2, strlen(string1)) == -1)
                        exit(2);
                close(fd[0]);

                printf("%s\n", string2);
        }
/* Child sends string, Parent receives string */
        return 0;
}

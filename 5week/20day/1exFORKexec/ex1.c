#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>

/* Get string from stdin and execute it from hijacked child process
 * may execute many processes with one execution
 */
int
main()
{
        while (1) {
                char line_buffer[200];
                line_buffer[0] = '\0';
                int char_c = 0;
                int cur_symb = '\0';

                while (cur_symb != '\n') {
                        cur_symb = getc(stdin);
                        line_buffer[char_c++] = cur_symb;
                }
                line_buffer[char_c - 1] = '\0';

/* Split line_buffer, to a string buffer */
                char *exec_argv[20];
                exec_argv[0] = strtok(line_buffer, " ");
                for (int i = 1; exec_argv[i - 1] != NULL; i++)
                        exec_argv[i] = strtok(NULL, " ");

                pid_t pid = fork();
                if (pid == -1) {
                        perror("Could not fork");
                        exit(errno);
                } else if (pid == 0) {
                        execvp(exec_argv[0], exec_argv);
                        perror("Exec failed");
                        exit(errno);

                } else {
                        int wstatus;
                        pid_t child_pid = wait(&wstatus);
                        if(!WIFEXITED(wstatus))
                                perror("Child did not exit normally");
                        else
                                printf("Child %d normal exit [%d]\n",child_pid, wstatus);
                }
        }
        return 0;
}

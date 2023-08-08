#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/wait.h>

int
main()
{
        int fd[2];

/* fd[0] - READ  pipe
 * fd[1] - WRITE pipe
 */
        if (pipe(fd) == -1) {
                perror("An error occurred opening pipe\n");
                exit(-1);
        }

        pid_t pid = fork();
        if (pid == -1) {
                perror("An error occurred. COuld not fork.\n");
                exit(-2);
        } else if (pid == 0) {
                /* Child */
                close(fd[0]); /* Zatvarqne na pipe-a za chetene, za da ne se oburka v parenta. (spodelen resurs) */
                int a;
                scanf("%d", &a);
                if (write(fd[1], &a, sizeof(a)) == -1){
                        perror("An error occurred. Could not write to fd.\n");
                        exit(-3);
                }
                close(fd[1]); /* Close pipe for writing */
                /* Syscall to write in fd.
                 * (passing information to the pipe,
                 * to another process
                 */
        } else {
                /* Parent */
                close(fd[1]); /* CLose pipe for writing */
                int b;
                if (read(fd[0], &b, sizeof(b)) == -1) {
                        perror("An error occurred. COuld not read fd.\n");
                        exit(-4);
                }
                close(fd[0]); /* CLose pipe for reading */
                printf("%d\n", b * 2);

        }

        return 0;
}

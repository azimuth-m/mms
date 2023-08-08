#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/wait.h>

/* Child chete ot nachalo do sredata
 * i zapisva v kanal svoq rezultat.
 * parent chete ot sredata do kraq,
 * chete rezultata na hcild-a
 * i sumira dvete sumi
 */

int
main()
{
        int fd[2];
        int chisla[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int n = sizeof(chisla)/sizeof(chisla[0]);
        int half = n/2;

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
                int sumC = 0;
                size_t i; 
                for (i = 0; i < half; i++)
                        sumC += chisla[i];
                if (write(fd[1], &sumC, sizeof(sumC)) == -1){
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
                int sumP;
                if (read(fd[0], &sumP, sizeof(sumP)) == -1) {
                        perror("An error occurred. COuld not read fd.\n");
                        exit(-4);
                }
                size_t i; 
                for (i = half; i < n; i++)
                        sumP += chisla[i];
                close(fd[0]); /* CLose pipe for reading */

                printf("Sum: %d\n", sumP);
        }

        return 0;
}

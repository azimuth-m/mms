#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

int (*pipes)[2];

uint64_t
digitSumFind(uint64_t num)
{
        if (num == 0)
                return 0;
        uint64_t sum = 0;
        uint64_t r;

        while (num != 0) {
                r = num % 10;
                sum = sum + r;
                num = num / 10;
        }
        return sum;
}

void
childFun(int child_index, char *argv[])
{
        /* Check filesize of file */
        struct stat sb;
        stat(argv[child_index+1], &sb);

        uint64_t sum = 0;
        uint64_t *buffer = malloc(sb.st_size);

        /* Open file and move contents to buffer */
        int fd;
        fd = open(argv[child_index+1], O_RDONLY);
        if (fd < 0) {
                perror("Unable to open file");
                exit(errno);
        }
        if (read(fd, buffer, sb.st_size) == 0) {
                perror("Unable to read file");
                exit(errno);
        }
        close(fd);

        for ( uint64_t i = 0; i < (sb.st_size/sizeof(uint64_t)); i++) {
                sum += digitSumFind(buffer[i]);
        }

        free(buffer);
        printf("Sum of proc %d, file \"%s\" == ", child_index, argv[child_index+1]);
        printf("%" PRIu64, sum);
        write(pipes[child_index][1], &sum, sizeof(sum));
        printf("\n");
}

int
main(int argc, char *argv[])
{
        
        int fd[argc-1][2];
        pipes = malloc(sizeof(int) * (argc-1));
        for (int i = 0; i < argc- 1; i++)
                pipe(pipes[i]);

        uint64_t *child_sum_write = malloc(sizeof(uint64_t) * (argc-1));
        pid_t pid;
        /* Da moje da se napravi s calloc i vsqko dete da si pishi na sumira v negoviq index */
        for (int i = 0; i < argc - 1; i++) {
                pid = fork();
                if (pid < 0) {
                        perror("Unable to fork. Exiting...");
                        exit(errno);
                } else if (pid == 0) {
                        childFun(i, argv);
                        return 0;
                }
                wait(NULL);
        }

        for (int i = 0; i < argc - 1; i++) {
                read(pipes[i][0], child_sum_write + i, sizeof(uint64_t));
                close(pipes[i][0]);
                close(pipes[i][1]);
        }

        uint64_t totalsum = 0;
        for (int i = 0; i < argc-1; i++) {
                totalsum += child_sum_write[i];
        }
        printf("\n\nTotal Sum: %" PRIu64, totalsum );

        /* Mnogo dolna zadacha */

        return 0;
}

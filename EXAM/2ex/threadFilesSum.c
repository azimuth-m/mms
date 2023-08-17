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

uint64_t TOTALSUM;
pthread_mutex_t lock;

struct threadArg {
        int id;
        char *argv;
};

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

void *
worker(void * arg)
{
        int child_index = ((struct threadArg *) arg)->id;
        char *argv = ((struct threadArg *) arg)->argv;
        /* Check filesize of file */
        struct stat sb;
        stat(argv, &sb);

        uint64_t sum = 0;
        uint64_t *buffer = malloc(sb.st_size);

        /* Open file and move contents to buffer */
        int fd;
        fd = open(argv, O_RDONLY);
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
        printf("Sum of proc %d, file \"%s\" == ", child_index, argv);
        printf("%" PRIu64, sum);

        pthread_mutex_lock(&lock);
        TOTALSUM += sum;
        pthread_mutex_unlock(&lock);
        printf("\n");

        return NULL;
}

int
main(int argc, char *argv[])
{
        pthread_t thread[argc - 1]; 
        struct threadArg *targs = malloc(sizeof(struct threadArg) * argc - 1);
        for (int i = 0; i < argc - 1; i++) {
                targs[i].id = i;
                targs[i].argv = argv[i+1];
                pthread_create(thread, NULL, worker, targs);
        }
        pthread_mutex_init(&lock, NULL);

        for (int i = 0; i < argc - 1; i++) {
                pthread_join(thread[i], NULL);
        }
        printf("\n\nTotal Sum: %" PRIu64, TOTALSUM );
        pthread_mutex_destroy(&lock);

        free(targs);
        /* Mnogo dolna zadacha sushto */

        return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/errno.h>

int
main()
{

        const char filename[] = "myFifoPipe";
        if (mkfifo(filename, 0777) == -1) {
                if (errno != EEXIST) {
                        perror("An error occurred opening fifo pipe");
                        strerror(errno);
                        exit(-1);
                }
        }
        printf("Opening...\n");
        int fd = open(filename, O_RDWR);
        printf("Opened\n");

        int myVal = 'A';
        if (write(fd, &myVal, sizeof(myVal)) == -1) {
                perror("Cannot write to file");
                exit(-1);
        }
        printf("Written %d in file %s with fd %d\n", myVal, filename, fd);
        close(fd);

        return 0;
}

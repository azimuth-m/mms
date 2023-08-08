#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
        srand(time(0));
        const char filename1[] = "NamedChannel1";

        int array1[10];
        size_t i;
        for (i = 0; i < 10; i++) {
                array1[i] = 32 + rand() % (100 - 32);
        }

        /* Create file NamedChannel1 */
        if (mkfifo(filename1, 0777) == -1) {
                if (errno != EEXIST) {
                        perror("An error occurred opening fifo pipe");
                        strerror(errno);
                        exit(1);
                }
        }

        /* Write 10 ints in file NamedChannel1 */
        int fd = open(filename1, O_WRONLY);
        if (fd == -1)
                exit(2);
        if (write(fd, array1, sizeof(array1)) == -1)
                exit(3);
        close(fd);


        return 0;
}

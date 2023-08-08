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
        const char filename1[] = "NamedChannel1";

        /* Read 10 ints from file NamedChannel1 */
        int fd = open(filename1, O_RDONLY);
        if (fd == -1)
                exit(2);
        int array2[10];
        if (read(fd, array2, sizeof(array2)) == -1)
                exit(3);

        size_t i;
        for (i = 0; i < 10; i++)
                printf("%d ", array2[i]);
        close(fd);


        return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

void
hexDump(char *argv[])
{
        /* Check for file size */
        struct stat sb;
        stat(argv[1], &sb);
        /* Create buffer with filesize */
        char *buff = malloc(sb.st_size);

        int fd = open(argv[1], O_RDONLY);

        read(fd, buff, sb.st_size);
        close(fd);
        // write(0, buff, sb.st_size); write to stdout directly
        for (long int i = 1; i <= sb.st_size; i++) {
                printf("%02x ", (unsigned char)buff[i-1]);
                if(!(i%16))
                        printf("\n");
        }
        free(buff);
        printf("\n");
}

void
byteDump(char *argv[])
{
        /* Check for file size */
        struct stat sb;
        stat(argv[1], &sb);

        /* Create buffer with filesize */
        char *buff = malloc(sb.st_size);

        int fd = open(argv[1], O_RDONLY);

        read(fd, buff, sb.st_size);
        close(fd);
        // write(0, buff, sb.st_size); write to stdout directly
        for (long int i = 1; i <= sb.st_size; i++) {
                for (size_t j = 8; j > 0; j--)
                        printf("%hhu", !!(buff[i-1] & (1 << (j-1))));
                printf(" ");
                if(!(i%16))
                        printf("\n");
        }
        free(buff);
        printf("\n");
}

int
main(int argc, char *argv[])
{

/* Spomenato ni e da ne pravim proverki za sustoqtelnost na danni ot cmd-line */

        /* Da, koda e neefikasen, no raboti =] */

        int opt;
        opt = getopt(argc, argv, "HB");
        switch(opt) {
                case 'H':
                        hexDump(argv);
                        break;
                case 'B':
                        byteDump(argv);
                        break;
        }
        return 0;
}

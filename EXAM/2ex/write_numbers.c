#include <stdio.h>
#include <inttypes.h>

int
main(int argc, char *argv[])
{
        uint64_t n;
        sscanf(argv[2], "%" PRIu64, &n);
        FILE *f1 = fopen(argv[1], "w");
        for (uint64_t i = 1; i <= n; i++)
                fwrite(&i, sizeof(i), 1, f1);
        fclose(f1);
        return 0;
}

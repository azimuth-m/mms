#include <stdio.h>

int
main(int argc, char *argv[])
{
        int n;
        sscanf(argv[2], "%d", &n);
        FILE *f1 = fopen(argv[1], "w");
        for (int i = 0; i < n; i++)
                fwrite(&i, sizeof(i), 1, f1);
        fclose(f1);
        return 0;
        print
}

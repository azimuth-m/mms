#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *
toUpper(const char *c)
{
        char *new_c, *temp;
        new_c = malloc(sizeof(char) * strlen(c)+1);
        temp = new_c;
        while(*c) {
                if (*c >= 'a' && *c <= 'z') {
                        *temp = *c - 0x20;
                } else {
                        *temp = *c;
                }
                c++;
                temp++;
        }
        *temp = '\0';
        return new_c;
}

int
main()
{
        char str[] = "asd123XYZ ll pqr^";
        

        printf("%s\n", str);
        char *str_mod = toUpper(str);
        printf("%s\n", str_mod);
        free(str_mod);
        return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *
encodeStr(char *str, size_t len)
{
        for (size_t i = 0; i < len; i += 2) {
                *(str + i) = *(str + i) + ('A' - '0');
        }
/* Veroqtno ima i po optimalen nachin (da se hardcodeva v arr) */
        for (size_t i = 1; i < len; i += 2) {
                switch (*(str + i)) {

                case '0':
                        *(str + i) = '!';
                        break;
                case '1':
                        *(str + i) = '#';
                        break;
                case '2':
                        *(str + i) = '/';
                        break;
                case '3':
                        *(str + i) = '~';
                        break;
                case '4':
                        *(str + i) = '=';
                        break;
                case '5':
                        *(str + i) = '`';
                        break;
                case '6':
                        *(str + i) = '\\';
                        break;
                case '7':
                        *(str + i) = '>';
                        break;
                case '8':
                        *(str + i) = '.';
                        break;
                case '9':
                        *(str + i) = ',';
                        break;
                }
        }

        char *str_mod = malloc(sizeof(char) * len+1);
        memcpy(str_mod, str, len+1);
        return str_mod;
}

int
main()
{
        char str[500];
        scanf("%s", str);
        size_t len = strlen(str);
        char *new_str = encodeStr(str, len);
        printf("%s\n", new_str);
        free(new_str);
        return 0;
}

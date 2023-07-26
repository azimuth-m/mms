#include <stdio.h>

int
my_strlen(const char *str) /* <const int *p> - Moje da se modva stoinostta
                            * na na ukazatelq
                            * Nemoje da se promenq stoinostta kum koqto ptr sochi
                            * chrez ukazatelq
                            *
                            * <int * const p> = &promenliva;
                            * ^^ nemoje da se modificira stoinostta na p
                            * p++; - greshka;
                            * *p = neshto - OK
                            *
                            * <int * const *p> - nemoje nito da se modificira
                            * stoinostta na ukazatelq, nito stoinostta kum koqto
                            * toi sichi
                            * */
{
        int i = 0;
        while (*(str++))
                i++;
        return i;
}

void
my_strcpy(char *dest, const char *src)
{
        /* memcpy(dest, src, my_strlen(src)+1); */
        while (*src)
                *(dest++) = *(src++);
        *dest = '\0';
}

void
my_strcat(char *dest, const char *src)
{
        dest += my_strlen(dest);
        my_strcpy(dest, src);
}

int
my_strcmp(const char *str1, const char *str2)
{
        while (*str1 == *str2 && *str2) {
                str1++;
                str2++;
        }
        return *str1 - *str2;
}

int
main()
{
        char str[100] = "Hello";
        char str1[100];
        char str2[200] = "1TEST";
        my_strcpy(str1, str);
        my_strcat(str2, str);
        printf("%s\n", str1);
        printf("Strlen: %d\n", my_strlen(str));
        printf("Strcat: %s\n", str2);
        printf("%s - %s = %d\n",str, str2, my_strcmp(str, str2));
        return 0;
}

#include <stdio.h>
#include <string.h>

int
atoi_rev(const char *a)
{
        if (!(*a))
                return 0;
        return (*a - '0') + atoi_rev(a+1)*10;
}

void
reverse(const char *str1, char *str2)
{
        str2 += strlen(str1);
        *str2-- = '\0';

        while (*str1)
                *str2-- = *str1++;
}

int
main()
{
        char a[] = "23";
        char b[10];
        reverse(a, b);
        printf("%d", atoi_rev(b));
        return 0;
}

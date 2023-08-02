#include <stdio.h>

#include <stdarg.h>

int
sum_variadic(int c, ...)
{
        va_list args;
        va_start(args, c);

        int sum = 0;
        sum += va_arg(args, int); // 1vi arg
        sum += va_arg(args, int); // 2ri arg
        sum += va_arg(args, int); // 3ti arg
        sum += va_arg(args, int); // 4ti arg
        //           ^^
        //           Tipa na arg, koito da se prochete
        va_end(args);

        return sum;
}

void
my_printf(const char *str, ...)
{
        va_list args;
        va_start(args, str);
        printf("[Custom Printf]");
        vprintf(str, args);
        va_end(args);
}

int
main()
{
        printf("%d\n", sum_variadic(4, 1, 2, 3, 40));
        my_printf("TEST\n");
        return 0;
}

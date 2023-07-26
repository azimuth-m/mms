#include <stdio.h>
#define VAR 5

int
factorial(int n)
{
	return (n < 2) ? 1 : n * factorial(n-1);
}

int
main(void)
{
printf("%d\n", factorial(VAR));
	return 0;
}

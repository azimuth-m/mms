#include <stdio.h>
#define VAR 7

int
fib(int n)
{
	return (n < 2) ? n : fib(n - 2) + fib(n - 1); 
}

int
main(void)
{
printf("%dth fib number == %d\n",VAR+1, fib(VAR));
	return 0;
}

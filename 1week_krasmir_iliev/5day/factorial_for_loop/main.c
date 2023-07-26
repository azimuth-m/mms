#include <stdio.h>
#define VAR 5

int
main(void)
{
	int result = 1; 

	for (int i = 1; i <= VAR; i++)
		result *= i;

	printf("%d! == %d\n", VAR, result);
	return 0;
}

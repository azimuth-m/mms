#include <stdio.h>
#include <math.h>

int main(void)
{

	int number = 347;
	printf("\nNumber: %d", number);

	int base = 10;
	int result = 0;
	int pos = 0;

	while (number > 0) {
		int digit = number % base;
		result += digit * pow(base, pos);
		pos++;
		number /= base;
	}

	printf("\nBase: %d\nResult: %d\n", base, result);
	return 0;
}

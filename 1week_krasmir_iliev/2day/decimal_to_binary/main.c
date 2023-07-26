#include <stdio.h>

int main(void)
{
	int number_in_decimal = 48;
	int base = 2;
	while (number_in_decimal > 0) {
		int remainder = number_in_decimal % base;
		number_in_decimal /= base;
		printf("%d\n", remainder);
	}
	return 0;
}

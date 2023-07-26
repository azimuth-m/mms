#include <stdio.h>

int main(void)
{
	int number_in_decimal;
	int base = 2;

	printf("\nEnter number in decimal notation: ");
	scanf("%d", &number_in_decimal);

	while (number_in_decimal > 0) {
		int remainder = number_in_decimal % base;
		number_in_decimal /= base;
		printf("%d ^\n", remainder);
	}
	return 0;
}

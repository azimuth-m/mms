#include <stdio.h>

int
main(void)
{
	int even_odd, count;

	printf("\nInput odd (0) or even (1): ");
	scanf("%d", &even_odd);

	printf("\nEnter count of counts ");
	scanf("%d", &count);

	int i;
	if (even_odd) {
		for (i = 2; i < 100 && count; i=i+2) {
			printf("%d\n", i);
			count--;
		}
	} else {
		for (i = 1; i < 100 && count; i=i+2) {
			printf("%d\n", i);
			count--;
		}
	}

	return 0;
}

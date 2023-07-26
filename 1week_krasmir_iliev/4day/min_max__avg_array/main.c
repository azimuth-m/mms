#include <stdio.h>

int
main(void)
{
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int a_lenght = sizeof(array) / sizeof(array[0]);
	int max_i = 0;
	int min_i = 0;
	float sum = 0;

	for (int i = 0; i < a_lenght; i++) {
		if (array[i] > array[max_i])
			max_i = i;
		else if (array[i] < array[min_i])
			min_i = i;
		sum += array[i];
	}

	printf("Min: array[%d] = %d\n", min_i, array[min_i]);
	printf("Max: array[%d] = %d\n", max_i, array[max_i]);
	printf("Avg: %f\n", sum / a_lenght);

	return 0;
}

#include <stdio.h>

void
swap_ints(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void
invert_array(int *a, int size)
{
	int start = 0;
	int end = size - 1;

	while (start < end) {
		swap_ints(&a[start], &a[end]);
		start++;
		end--;
	}
}
void
print_array(int *a, int size)
{
	for (int i = 0; i < size; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}
}

int
main(void)
{
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int a_lenght = sizeof(array) / sizeof(array[0]);

	print_array(array, a_lenght);
	invert_array(array, a_lenght);
	printf("\nCall _invert_array\n");
	print_array(array, a_lenght);



	return 0;
}

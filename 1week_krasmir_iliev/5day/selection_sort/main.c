#include <stdio.h>

void
selection_sort(int *a, int len)
{
	int temp;

	for (int i = 0; i < len - 1; i++) {
		int min_i = i;
		for (int j = i + 1; j < len; j++) {
			if (a[j] < a[min_i])
				min_i = j;
		}

		if (min_i != i) {
			temp = a[i];
			a[i] = a[min_i];
			a[min_i] = temp;
		}
	}
}

void
print_array(int *a, int len)
{
	for (int i = 0; i < len; i++) {
		printf("a[%d] = 0x%X\n", i, a[i]);
	}
}

int
main(void)
{
	int a[] = {0xB, 0xB, 0xC, 0xA};
	int len = sizeof(a)/sizeof(a[0]);

	print_array(a, len);
	selection_sort(a, len);
	printf("\n");
	print_array(a, len);

	return 0;
}

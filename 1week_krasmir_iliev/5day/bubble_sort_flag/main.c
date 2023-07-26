#include <stdio.h>

void
bubble_sort_flag(int *a, int len)
{
	unsigned char flag = 0;
	int temp;
	int j = 0;

	do {
		flag = 0;
		for (int i = 0; i < len-j-1; i++) {
			if (a[i] > a[i+1]) {
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				flag = 1;
			}
		}
		j++;
	} while (flag);
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
	int a[] = {0xB, 0xB, 0xC, 0xA, 0xFF, 0x00, 0x2};
	int len = sizeof(a)/sizeof(a[0]);

	print_array(a, len);
	bubble_sort_flag(a, len);
	printf("\n");
	print_array(a, len);

	return 0;
}

#include <stdio.h>

int
linear_search(int *a, int len, int key)
{
	for (int i = 0; i < len; i++) {
		if (a[i] == key)
			return i;
	}
	return -1;
}

int
main(void)
{
	int a[] = {0xC, 0xA, 0xF, 0xE};
	int len = sizeof(a)/sizeof(a[0]);
	int key = 0xE;
	int index;
	index = linear_search(a, len, key);

	printf("%d\n", index);
	return 0;
}

#include <stdio.h>

int
binary_search(int *a, int len, int key)
{
	int low = 0;
	int high = len - 1;
	int mid;
	while (low <= high) {
		mid = low + (high - low)/2;

		if (key == a[mid])
			return mid;

		if (key > a[mid])
			low = mid + 1;
		else
			high = mid - 1;		
	}
	return -1;
}

int
main(void)
{
	int a[] = {0xA, 0xB, 0xC, 0xD};
	int len = sizeof(a)/sizeof(a[0]);
	int key = 0xD;
	int index;
	index = binary_search(a, len, key);

	printf("%d\n", index);
	return 0;
}

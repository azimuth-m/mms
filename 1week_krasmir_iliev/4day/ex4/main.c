#include <stdio.h>

int
get_int_val_with_int_ofs(int *p, int ofs)
{
	return *(p + ofs);
}

int
main(void)
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int a_len;

	a_len = sizeof(a)/sizeof(a[0]);

	int ofs = 3;

	printf("%d\n", get_int_val_with_int_ofs(a, ofs));
	return 0;
}

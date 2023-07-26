#include <stdio.h>

void
switch_pointer_pointing(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int
main(void)
{
	int a = 5;	
	int b = 10;

	int *pa = &a;
	int *pb = &b;

	printf("\n*pa = %d\n*pb = %d\n", *pa, *pb);
	switch_pointer_pointing(pa, pb);
	printf("\n*pa = %d\n*pb = %d\n", *pa, *pb);

	return 0;
}

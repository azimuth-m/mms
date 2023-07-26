#include <stdio.h>

int
my_fx(int a, int *b)
{
	return a + *b;
}

int
main(void)
{
	int x = 5;
	int y = 11;
	
	int (*fxp)(int, int *); /* Declaring a pointer to a function,
				 * which has arguments 
				 * <int> and <pointer to int>
				 */ 

	fxp = my_fx;
	
	printf("%d\n", fxp(x, &y)); /* Call my_fx, through
				     * pointer fxp, and store res in
				     * an output buffer as %d
				     *
				     * Other possible call:
				     * 	var = (*fxp)(x, &y);
				     */

	printf("%d\n", (*fxp)(x, &y));

	return 0;
}

#include <stdio.h>

/* The following code demonstrates,
 * calling a function, which requires
 * a pointer to another function,
 * as a second parameter.
 */

int
caller(int a, int (*callee_fx_ptr)(int))
{
	/* printf("%d\n", (*callee_fx_ptr)(a)); */
	printf("%d\n", callee_fx_ptr(a));
}

int
callee(int a)
{
	return 2 * a;
}

int
main(void)
{

	int (*fxp)(int);/* Declare a pointer to a function,
			 * which returns an integer and takes
			 * one integer paramter.
			 */

	fxp = callee;	/* Assign address of <callee> to <fxp> */

	caller(9, fxp); /* Call <caller>, passing parameters
			 * integer <9> and a pointer to <callee>, <fxp>
			 */
	return 0;
}

#include <stdio.h>
#include "my_math.h"

int main(int argc, char *argv[])
{
	double num = 5;
	double calc_sq = square(num);
	double calc_cu = cube(num);
	
	printf("\nNum: %f\nSquare: %f\nCube: %f\n", num, calc_sq, calc_cu);	
	return 0;
}


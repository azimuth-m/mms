#include <stdio.h>

int
main(void)
{
	char grade;
	scanf("%c", &grade);

	switch (grade) {
	
	case 'a':
		printf("\nA\n");
		break;
	case 'b':
		printf("\nb\n");
		break;
	case 'c':
		printf("\nc\n");
		break;
	case 'd':
		printf("\nd\n");
		break;
	case 'f':
		printf("\nf\n");
		break;
	default:
		printf("\nNo Grade\n");
		break;
	}
	return 0;
}

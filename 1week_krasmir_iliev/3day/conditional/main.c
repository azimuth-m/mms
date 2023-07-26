#include <stdio.h>

int
main(void)
{
	int age, weight;

	printf("Age in: ");
	scanf("%d", &age);
	printf("Weight in: ");
	scanf("%d", &weight);

	if (age < 18)
		printf("\nunder 18\n");
	else if (age > 17 && weight < 100)
		printf("over 17 and under 100kg\n");
	else
		printf("over 17\n");

	return 0;
}

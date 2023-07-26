#include <stdio.h>

double conv(double f_temp)
{
	return (f_temp - 32) * 5 / 9;
}
int main()
{
	double fahrenheit;
	printf("Enter temperature in Fahrenheit: ");
	scanf("%lf", &fahrenheit);
	printf("%.2lf°F is equal to %.2lf°C\n", fahrenheit, conv(fahrenheit));
return 0;
}

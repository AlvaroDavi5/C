#include <stdio.h>

int main()
{
	float fahrenheit, celsius;

	printf("Digite uma temperatura em Fahrenheit...\n");
	scanf("%f", &fahrenheit);

	celsius = (fahrenheit - 32.0) * 5.0 / 9.0;

	printf("%.2f °C\n", celsius);

	return 0;
}
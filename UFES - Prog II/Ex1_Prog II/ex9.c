#include <stdio.h>

int main()
{
	float kelvin, celsius;

	printf("Digite uma temperatura em Kelvin...\n");
	scanf("%f", &kelvin);

	celsius = kelvin - 273.15;

	printf("%.2f °C\n", celsius);

	return 0;
}
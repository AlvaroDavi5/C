#include <stdio.h>

int main()
{
	float cels, fahren;

	printf("Digite uma temperatura em Celsius...\n");
	scanf("%f", &cels);

	fahren = (cels * 9.0 / 5.0) + 32.0;

	printf("%.2f °F\n", fahren);

	return 0;
}
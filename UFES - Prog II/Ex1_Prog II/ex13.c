#include <stdio.h>

int main()
{
	float quilometro, milha;

	printf("Insira a velocidade em quilometros \n");
	scanf("%f", &quilometro);

	milha = 1.61 / quilometro;
	printf("%.2f \n", milha);

	return 0;
}
#include <stdio.h>

int main()
{
	float milha, quilometro;

	printf("Insira a velocidade em milhas \n");
	scanf("%f", &milha);

	quilometro = 1.61 * milha;
	printf("%.2f \n", quilometro);

	return 0;
}
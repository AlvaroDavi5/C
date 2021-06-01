#include <stdio.h>

int main()
{
	float num, quinto;

	printf("Por favor, digite 1 número real...\n");
	scanf("%f", &num);

	quinto = (num / 5);

	printf("%.2f \n", quinto);

	return 0;
}
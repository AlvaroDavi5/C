#include <stdio.h>

int main()
{
	int v1, v2, v3, som;

	printf("Por favor, digite 3 valores inteiros...\n");
	scanf("%i %i %i", &v1, &v2, &v3);

	som = v1 + v2 + v3;

	printf("%d \n", som);

	return 0;
}
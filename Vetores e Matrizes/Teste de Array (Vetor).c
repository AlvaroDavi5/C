#include <stdio.h>
#include <stdlib.h>

int main()
{
	int numbs[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // vetor com 10 espaços
	int i;

	printf("VETOR: ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", numbs[i]);
	}
	printf("\n");


	char vetorchar[4] = {'O', 'l', 'a'};
	printf("Vetor de caracteres: %s\n", vetorchar);


	char string[20] = "E ai pessoal";

	printf("STRING:\n");
	for (i = 0; string[i] != '\0'; i++) // contar caractere por caractere ate o caractere nulo
	{
		printf("Posicao %d -> '%c'\n", i, string[i]);
	}
	printf("Posicao %d -> '%c'\n", i, string[i]);

	printf("\n");

	return 0;
}

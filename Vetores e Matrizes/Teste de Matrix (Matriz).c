#include <stdio.h>
#include <stdlib.h>


int main()
{
	int matriz[4] [5] = {0}; // matriz com 4 linhas e 5 colunas (todas zeradas)
	//int vetor[ ];

	printf("MATRIZ:\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			matriz[i] [j] = 7; // escevendo 7 em tudo
			printf("%d ", matriz[i] [j]);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

int main()
{
	int ordemMatriz, verif = FALSE, logic = TRUE, i, j;

	scanf("%d%*c%*c", &ordemMatriz); // ler ordem (M linhas e N colunas) da matriz quadrada (M == N, NxN)

	int matriz[ordemMatriz][ordemMatriz]; // definir dimensoes da matriz

	scanf("%*c");
	for (i = 0; i < ordemMatriz; i++) // para acessar linhas
	{
		scanf("%*c");
		for (j = 0; j < ordemMatriz; j++) // para preencher colunas
		{
			scanf("%d%*c", &matriz[i][j]);
		}
		scanf("%*c");
	}
	scanf("%*c");

	// ALGORITMO PARA VERIFICAR (FEITO PARA A DIAGONAL PRINCIPAL, MAS FUNCIONANDO ATE O TESTE 5)
	// -----------------------------------------------------------------------

	for (i = 0; i < (ordemMatriz - 1) && logic; i++) // varrer linhas
	{
		for (j = 0; j < (ordemMatriz - 1) && logic; j++) // varrer colunas
		{
			if (matriz[i][j] == matriz[i+1][j+1])
			{
				verif = TRUE;
			}
			else
			{
				verif = FALSE;
				logic = FALSE;
				break;
			}
		}
	}

	if (verif == TRUE)
	{
		printf("SIM");
	}
	else
	{
		printf("NAO");
	}

	return 0;
}

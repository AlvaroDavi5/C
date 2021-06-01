/*

Ler numero N de produtos e retornar produtos:
	em FALTA (em ordem de ocorrencia)
	de MAIOR preço (em ordem de ocorrencia, caso empate entre produtos)
	de MENOR preço (em ordem de ocorrencia, caso empate entre produtos)
Os produtos serão dados por seus códigos, preços e quantidade em estoque

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h> // por estar no diretório do compilador, aqui a inclusão do arquivo biblioteca é feita com < >
#include "prodfunc.h" // por estar no mesmo diretório, aqui a inclusão do arquivo biblioteca é feita com " "

// protótipos das funções em cabeçalho/header 'prodfunc.h' e código fonte/sourcecode das funções em 'produte_functions.c'

int main()
{
	int n;
	tProduto pTemp, pMax, pMin;

	scanf("%d", &n);

	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			pTemp = LeProduto();

			if (i == 0)
			{
				pMax = pTemp;
				pMin = pTemp;
			}

			// FALTA
			if (TemProdutoEmEstoque(pTemp))
			{
				// MAIOR
				if (EhProduto1MaiorQ2(pMax, pTemp))
				{
					pMax = pTemp;
				}

				// MENOR
				if (EhProduto1MenorQ2(pMin, pTemp))
				{
					pMin = pTemp;
				}
			}
			else
			{
				printf("FALTA:");
				ImprimeProduto(pTemp);

				// MAIOR
				if (EhProduto1MaiorQ2(pMax, pTemp))
				{
					pMax = pTemp;
				}

				// MENOR
				if (EhProduto1MenorQ2(pMin, pTemp))
				{
					pMin = pTemp;
				}
			}
		}

		// MAIOR
		printf("MAIOR:");
		ImprimeProduto(pMax);	

		// MENOR
		printf("MENOR:");
		ImprimeProduto(pMin);	
	}

	return 0;
}
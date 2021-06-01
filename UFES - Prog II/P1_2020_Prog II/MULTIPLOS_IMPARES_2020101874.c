/*

	ler intervalo aberto m, n
	checar se n <= m
		se sim, pedir novamente, se não, não pedir
	verificar todos os valores impares do intervalo
	imprimir, por linha, o IMPAR seguido de --> e a lista de MULTIPLOS dele maior que ele dentro do intervalo, seguido de : e a SOMA de todos os multiplos
	se nao ha impar no intervalo, nao imprimir nada
	se nao ha multiplos, imprimir apenas o impar

	imprimir soma total de todos impares (soma total)

	considerar pelo menos 2 algarismos ao imprimir

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int verifImpar(int n, int m);
int imprimirMultiplos(int impar, int n, int m);
int somarImpares(int impares);

int main()
{
	int n, m;

	while (1)
	{
		scanf("%d %d", &n, &m);

		if (n <= m)
		{
			verifImpar(n, m);
			break;
		}
	}

	return 0;
}

int verifImpar(int n, int m)
{
	for (int i = n+1; i < m; i++)
	{
		if (i % 2 != 0)
		{
			printf("%d", i);
			imprimirMultiplos(i, n, m);
			somarImpares(i);
			printf("\n");
		}
	}

	return 0;
}

int imprimirMultiplos(int impar, int n, int m)
{
	int num = 1;
	int mult = 0, soma = 0;
	int seta = 0, pontos = 0;

	while (num < m)
	{
		if (seta == 0)
		{
			printf(" -->");
			seta++;
		}

		mult = impar * num;

		if (mult > impar && mult < m)
		{
			printf(" %d", mult);
			soma += mult;
		}
		if (pontos == 0 && mult != 0)
		{
			printf(" : %d", soma);
			pontos++;
		}

		num++;
	}
	if (pontos == 0)
			{
				printf(" : %d", soma);
				pontos++;
			}
	
	num = n;

	return 0;
}

int somarImpares(int impares)
{
	int somaF;

	if (impares % 2 != 0)
	{
		somaF += impares;
	}

	return somaF;
}

// by Alvaro Davi, Eng Comp UFES, 2020

#include <stdio.h>

int EhPrimo(int num);
void ImprimeMultiplos(int num, int max);

int main()
{
	int n, m, num;

	scanf("%d %d", &n, &m);

	for (int i = n+1; i < m; i++) // aumentar i de n ate m (intervalo aberto)
	{
		if (EhPrimo(i)) // verificar, por funcao, se e primo
		{
			printf("%i \n", i);
			ImprimeMultiplos(i, m);
		}
	}

	return 0;
}

int EhPrimo(int num)
{
	int verif = 0;

	for (int i = 2; i <= (num / 2); i++) // aumenta i ate metade de num (o suficiente para saber se e primo)
	{
		if (num % i == 0) // se o resto da divisao inteira de num por i for 0, entao nao e primo
		{
			verif++;
			break; // contrario de 'continue'
		}
	}

	if (verif == 0) // se o verificador ainda for 0 apos o fim da repeticao, entao e primo
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void ImprimeMultiplos(int num, int max)
{
	int mult = 0, cont = 0;

	for (int i = 2; i < max; i++) // aumenta i ate max
	{
		mult = num * i;

		if (mult < max)
		{
			printf("%i ", mult);
			cont = 1;
		}
		else
		{
			break;
		}
	}

	if (cont != 0)
	{
		printf("\n");
	}

	for (int i = 2; i < max; i++)
	{
		mult = num * i;

		if ((mult >= max) && cont == 0)
		{
			printf("* \n");
			break;
		}
	}
}

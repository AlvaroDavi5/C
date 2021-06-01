// by Alvaro Davi, Eng Comp, UFES, 2020

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int totalNumb, firstN, num;
	int control = 0;
	int qtdP = 0, qtdI = 0;

	scanf("%d", &totalNumb);

	for (int i = 0; i < totalNumb; ++i)
	{
		scanf("%d", &num);

		if (control == 0)
		{
			firstN = num; // PEGAR VALOR DO PRIMEIRO NUMERO
			control++;
		}

		// CONTAR PARES E IMPARES
		if ((num % 2) == 0)
		{
			qtdP++;
		}
		else /* (num % 2) != 0 */
		{
			qtdI++;
		}
	}

	if ((firstN % 2) == 0)
	{
		printf("QTD PARES:%d", qtdP);
	}
	if ((firstN % 2) != 0)
	{
		printf("QTD IMPARES:%d", qtdI);
	}

	return 0;
}

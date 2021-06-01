/*

Ler inteiros, retornar maior lido e media

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>

int main()
{
	int num = 0, tempNum, maior;
	float soma, media = 0;

	for (int i = 0; 1; i++)
	{
		scanf("%i", &tempNum);
		if (tempNum == 0)
		{
			break;
		}

		(tempNum > num) ? (num = tempNum) : 0; // ARMAZENA O MAIOR VALOR DIGITADO

		soma += tempNum;
		media = soma / (1+i); // DIVISOR DA MEDIA

		printf("%i ", num);
		printf("%.6f\n", media);
	}

	return 0;
}
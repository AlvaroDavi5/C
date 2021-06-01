/*

Imprimir a quantidade de numeros negativos e positivos, a soma dos negativos e a soma dos positivos de uma sequencia de numeros

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>

int main()
{
	char caract;
	int num, qtdNeg, qtdPos, somaNeg, somaPos;

	qtdNeg = 0;
	qtdPos = 0;
	somaNeg = 0;
	somaPos = 0;
	caract = ' ';

	while (caract == ' ' || caract == '\n')
	{
		caract = '\0';
		scanf("%d", &num);
		scanf("%c", &caract);

		if (num < 0)
		{
			qtdNeg++;
			somaNeg += num;
		}
		if (num > 0)
		{
			qtdPos++;
			somaPos += num;
		}
	}

	printf("%d %d %d %d", qtdNeg, qtdPos, somaNeg, somaPos);

	return 0;
}
/*

Calcular aprovação por média

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <math.h>

int main()
{
	int n1, n2;
    float media;

	scanf("%i %i", &n1, &n2);
	
    media = ((n1 + n2)/2.0);

	if (media >= 7.0)
	{
		printf("%.1f - Aprovado", media);
	}

    if (media < 5.0)
	{
		printf("%.1f - Reprovado", media);
	}

    if (media >= 5.0 && media < 7.0)
	{
		printf("%.1f - De Recuperacao", media);
	}

    return 0;
}

/*

Mostrar sequencia de primos ate um dado numero

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <stdlib.h>


int main()
{
	int qtd, primo = 0, n = 2, i = 2;

	scanf("%d", &qtd);

	for (n; n <= qtd; n++)
	{
		while (i < n)
		{
			if (n % i == 0)
			{
				primo++;
			}
			i++;
		}

		i = 2;

		if (primo == 0)
		{
			printf("%d ", n);
		}

		primo = 0;
	}

	return 0;
}
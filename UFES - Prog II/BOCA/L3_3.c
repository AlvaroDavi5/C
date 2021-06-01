/*

Mostrar sequencia de primos de um intervalo (com funcao)

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <stdlib.h>

int EhPrimo(int num);

int main()
{
	int n, m;

	scanf ("%d%d", &n, &m);

	for(n = n+1; n < m; n++)
	{
		EhPrimo(n);

		if (EhPrimo(n) == 1)
		{
        	printf("%d ", n);
        }
	}

	return 0;
}

int EhPrimo(int num)
{
	int i, p, div;
	p = 0;

	for(i=1; i<=num; i++)
	{
		div= num%i;

		if(div==0)
		{
			p++;
		}
	}

	if(p==2)
	{
		return (1);
	}
	else
	{
		return (0);
    }
}
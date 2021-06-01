/*

Imprimir tabuada de um intervalo

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>

int main()
{
	int n, m, cont, res;

	scanf("%d %d", &n, &m);

	for (int i = n; i <= m; i++)
	{
		n = i;
		cont = 1;
		while (cont <= 10)
		{
			res = n * cont;
			printf("%d x %d = %d\n", n, cont, res);
			cont++;
		}
	}

	return 0;
}
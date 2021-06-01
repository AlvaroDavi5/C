/*

Calcular valor de PI de acordo com a raiz do somatorio de 6/k²

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <math.h>

int main()
{
	int n, k;
	float soma = 0, op;

	scanf("%d", &n);
	soma = 0;

	for (k = 1; k <= n; k++)
	{
		op = 6.00/(k*k);
		soma += op;
	}

	printf("%.6f", sqrt(soma));

	return 0;
}

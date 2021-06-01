/*

Imprimir maior numero

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <math.h>

int main()
{
	int n1, n2;

	scanf("%d %d", &n1, &n2);
	
	if (n1 > n2)
	{
		printf(" N1 = %d", n1);
	}
	
	if (n1 < n2)
	{
		printf(" N2 = %d", n2);
	}

	if (n1 == n2)
	{
		printf("N1 = N2");
	}

    return 0;
}

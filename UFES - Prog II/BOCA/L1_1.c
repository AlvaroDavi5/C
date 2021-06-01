/*

Somar a raiz quadrada de 2 números

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <math.h>

int main()
{
	int n1, n2;
	float r;

	scanf("%i %i", &n1, &n2);
	r = sqrt(n1) + sqrt(n2);
	printf("%.2f", r);

	return 0;
}

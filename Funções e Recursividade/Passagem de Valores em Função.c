#include <stdio.h>
#include <math.h>

int aumentar(int num)
{
	num++;
	return num; // passagem por valor, as alterações são feitas localmente e o resultado é retornado
}

void diminuir(int *n)
{
	*n = *n - 1; // passagem por referência, as alterações são feitas na variável usada como parâmentro, pois foi usado ponteiro
	return;
}

int main()
{
	int n, numT;

	scanf("%d", &n);

	numT = aumentar(n);
	printf("O valor retornado pela funcao foi %d \n", numT);

	diminuir(&n);
	printf("O valor de N foi alterado pela função e agora eh: %d \n", n);

	return 0;
}
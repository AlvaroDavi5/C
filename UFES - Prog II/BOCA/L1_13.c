/*

Dividir itens entre pessoas

Alvaro Davi, Eng Comp UFES, 2020


Se o n de Itens é maior que o n de Pessoas e o resto da divisão não é 0, o resto da divisão corresponde à última pessoa.
Se o n de Itens é maior que o n de Pessoas e o resto da divisão é 0, o n de Pessoas corresponde à última pessoa.
Se o n de Pessoas é igual ao n de Itens o resto da divisão é 0, logo, o n de Pessoas corresponde à última pessoa.
Se o n de Pessoas é maior que o n de Itens, o n de Itens corresponde à última pessoa.

*/

#include <stdio.h>
#include <math.h>

int main()
{
	int nPes, nItem, resto, result;

	scanf("%d %d", &nPes, &nItem);

	if (nItem > nPes)
	{
		resto = (nItem % nPes);

		if (resto == 0)
		{
			result = nPes;
		}

		if (resto != 0)
		{
			result = resto;
		}
	}

	if (nItem < nPes)
	{
		result = nItem;
	}

	if (nItem == nPes)
	{
		result = nPes;
	}

	printf("RESP:%d", result);

    return 0;
}
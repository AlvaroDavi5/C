/*

Ler Datas e Informar se o Ano é Bissexto

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <stdlib.h>
#include "leapyearfunc.h"

int main()
{
	int n;
	tData data;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		data = lerData();
		imprimeData(data);
		if (ehBissexto(data.ano))
		{
			printf(":Bisexto\n");
		}
		else
		{
			printf(":Normal\n");
		}
	}

	return 0;
}
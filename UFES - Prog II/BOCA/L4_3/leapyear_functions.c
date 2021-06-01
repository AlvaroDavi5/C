#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "leapyearfunc.h" 

tData lerData()
{
	tData dataTemp;
	int d, m, a;

	scanf("%d %d %d", &d, &m, &a);
	dataTemp = defineDMA(d, m, a);

	return dataTemp;
}

tData defineDMA(int dia, int mes, int ano)
{
	tData dataTmp;

	if(mes == 2 && dia > 28)
	{
		if (ehBissexto(ano))
		{
			dia = 29;
		}
		else
		{
			dia = 28;
		}
	}

	if (mes < 1)
	{
		mes = 1;
	}
	else if (mes > 12)
	{
		mes = 12;
	}

	dataTmp.dia = dia;
	dataTmp.mes = mes;
	dataTmp.ano = ano;

	return dataTmp;
}

int ehBissexto(int ano)
{
	return (((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0));
}

void imprimeData(tData data)
{
	printf("'%02d/%02d/%04d'", data.dia, data.mes, data.ano);
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "datafunc.h" 

// todas as funções
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

	if (mes < 1)
	{
		mes = 1;
	}
	else if (mes > 12)
	{
		mes = 12;
	}
	
	int qtd_Dias = diasDoMes(mes, ano);

	if (dia < 1)
	{
		dia = 1;
	}
	else if (dia > qtd_Dias)
	{
		dia = qtd_Dias;
	}

	dataTmp.dia = dia;
	dataTmp.mes = mes;
	dataTmp.ano = ano;

	return dataTmp;
}

int diasDoMes(int mes, int ano)
{
	int qtd_Dias;

	if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
	{
		qtd_Dias = 31;
	}
	if (mes == 2)
	{
		if (ehBissexto(ano))
		{
			qtd_Dias = 29;
		}
		else
		{
			qtd_Dias = 28;
		}
	}
	if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
	{
		qtd_Dias = 30;
	}

	return qtd_Dias;
}

int ehBissexto(int ano)
{
	return (((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0));
}

tData aumentaDMA(tData data)
{
	if (data.dia < diasDoMes(data.mes, data.ano)) // aumenta dia ate o maximo de dias do mes
	{
		data.dia++;
	}
	else // reinicia dia se maior que o maximo de dias do mes
	{
		data.dia = 1;
		if (data.mes < 12) // aumenta mes ate o maximo de meses do ano
		{
			data.mes++;
		}
		else // reinicia mes se maior que maximo de meses do ano
		{
			data.mes = 1;
			data.ano++; // aumenta ano com a funcao em loop, ate igualar a data final
		}
	}

	return data;
}

int ehIgual(tData data, tData dataFim)
{
	return ((data.dia == dataFim.dia) && (data.mes == dataFim.mes) && (data.ano == dataFim.ano));
}

void imprimeData(tData data)
{
	printf("'%02d/%02d/%04d'", data.dia, data.mes, data.ano); // o formato '%02d %02d %04d' permite imprimir com tal numero de casas decimais, inclusos zeros a esquerda 
}

/*

	Q1 da P1: Verificar Validade de Datas
	Alvaro Davi, Eng Comp, UFES, 2020

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ehBissexto(int ano);
int diasDoMes(int mes, int ano);

int main()
{
	int dia, mes, ano, qtd_dias;

	scanf("%d %d %d", &dia, &mes, &ano);

	qtd_dias = diasDoMes(mes, ano);

	if ((mes >= 1 && mes <= 12) && (ano <= 2020) && (dia >= 1 && dia <= qtd_dias))
	{
		printf("Data valida");
	}
	else
	{
		printf("Data invalida");
	}

	return 0;
}

int ehBissexto(int ano)
{
	return (((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0));
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
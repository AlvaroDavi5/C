/*

	Ler entrada (xx-xx-xxxx)
	Ignorar '-'
	Separar dia, mes e ano em formato inteiro

	Aplicar ALGORITMO PARA CALENDARIO GREGORIANO
		Pegar os 2 ultimos numeros do ano (AA)
		Somar AA a sua divisao inteira por 4 (AA + (AA divInt 4))
		Calcular o resto da divisao por 7 do resultado da ultima soma
		Armazenar ↑ como codigo do ano
		Subtrair 1 de ↑ se o ano for bissexto ((divisivel por 4 E nao-divisivel por 100) OU divisivel por 400)
		Armazenar codigos dos meses →
		Armazenar codigos dos seculos →

	ALGORITMO PARA DIA DO ANO
		dia_aux = codigo do ano + codigo do mês + codigo do século + dia do mês
		se for ano bissexto, subtrair 1
		calcular o resto da divisao por 7 de dia_aux. Isso retornará um valor entre 0 e 6, que representa o dia da semana
		0 = Domingo, ... , 6 = Sabado

	Continuar lendo datas (separadas por ' ') e aplicando ALGORITMOS enquanto '!' não for digitado

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int algoGrego(int dia, int mes, int ano, int contD); // algoritmo Gregoriano
int algoDia(int cod_ano, int cod_mes, int cod_sec, int dia_mes, int ano, int mes, int cnt);
int dias_Sem(int dia_sem, int cont);
int ehBissexto(int ano);

int main()
{
	int dia, mes, ano;
	int contD = 0;

	while ((scanf("%d-%d-%d ", &dia, &mes, &ano)) == 3)
	{
		algoGrego(dia, mes, ano, contD);
		contD++;
	}

	return 0;
}

int algoGrego(int dia, int mes, int ano, int contD)
{
	int cnt = contD;
	int cod_ano = 0;

	int AA = ano % 100;
	AA += (AA / 4);
	// cod_ano
	cod_ano = AA % 7;

	// cod_mes
	int cod_mes;
	switch (mes)
	{
		case 1:
			cod_mes = 0;
			break;
		case 2:
			cod_mes = 3;
			break;
		case 3:
			cod_mes = 3;
			break;
		case 4:
			cod_mes = 6;
			break;
		case 5:
			cod_mes = 1;
			break;
		case 6:
			cod_mes = 4;
			break;
		case 7:
			cod_mes = 6;
			break;
		case 8:
			cod_mes = 2;
			break;
		case 9:
			cod_mes = 5;
			break;
		case 10:
			cod_mes = 0;
			break;
		case 11:
			cod_mes = 3;
			break;
		case 12:
			cod_mes = 5;
			break;
		default:
			break;
	}

	// cod_sec
	int cod_sec;
	if (ano >= 1700 && ano < 1800)
	{
		cod_sec = 4;
	}
	if (ano >= 1800 && ano < 1900)
	{
		cod_sec = 2;
	}
	if (ano >= 1900 && ano < 2000)
	{
		cod_sec = 0;
	}
	if (ano >= 2000 && ano < 2100)
	{
		cod_sec = 6;
	}
	if (ano >= 2100 && ano < 2200)
	{
		cod_sec = 4;
	}
	if (ano >= 2200 && ano < 2300)
	{
		cod_sec = 2;
	}
	if (ano >= 2300 && ano < 2400)
	{
		cod_sec = 0;
	}

	algoDia(cod_ano, cod_mes, cod_sec, dia, ano, mes, cnt);

	return 0;
}

int algoDia(int cod_ano, int cod_mes, int cod_sec, int dia_mes, int ano, int mes, int cnt)
{
	int cont = cnt;
	int dia_aux = 0;
	
	dia_aux = cod_ano + cod_mes + cod_sec + dia_mes;

	// bissexto
	if (ehBissexto(ano) && (mes == 1 || mes == 2))
	{
		dia_aux--;
	}

	int dia_sem = (dia_aux % 7);
	dias_Sem(dia_sem, cont);

	return 0;
}

int dias_Sem(int dia_sem, int cont)
{
	int dia = dia_sem;
	int contador = cont;

	if (contador != 0)
	{
		printf(", ");
	}

	switch (dia)
	{
		case 0:
			printf("DOMINGO");
			break;
		case 1:
			printf("SEGUNDA");
			break;
		case 2:
			printf("TERCA");
			break;
		case 3:
			printf("QUARTA");
			break;
		case 4:
			printf("QUINTA");
			break;
		case 5:
			printf("SEXTA");
			break;
		case 6:
			printf("SABADO");
			break;
		default:
			break;
	}

	return 0;
}

int ehBissexto(int ano)
{
	return (((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0));
}

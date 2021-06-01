/*

Verificar Dia da Semana dado o Número

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void verifyDay(int day);

int main()
{
	int dayofweek;

	scanf("%d", &dayofweek);

	verifyDay(dayofweek);

	return 0;
}

void verifyDay(int day)
{
	switch (day)
	{
	case 1:
		printf("Domingo");
		break;
	case 2:
		printf("Segunda");
		break;
	case 3:
		printf("Terca");
		break;
	case 4:
		printf("Quarta");
		break;
	case 5:
		printf("Quinta");
		break;
	case 6:
		printf("Sexta");
		break;
	case 7:
		printf("Sabado");
		break;
	default:
		printf("Invalido");
		break;
	}

	return;
}
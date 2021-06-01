/*

Imprimir mes, dias do mes, ano e se ano é bissexto

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>

int main()
{
	int mes, diasMes, ano, biSex, anular;

	scanf("%i %i", &mes, &ano);
	biSex = 0;
	anular = 0;

	// SE ANO BISSEXTO
	if ((ano % 4 == 0) && (ano % 100 != 0) || (ano % 400 == 0))
	{
		biSex = 1;
	}

	// MESES
	switch (mes)
	{
	case 1:
		printf("janeiro");
		diasMes = 31;
		break;
	case 2:
		printf("fevereiro");
		if (biSex == 1)
		{
			diasMes = 29;
		}
		else
		{
			diasMes = 28;
		}
		break;
	case 3:
		printf("marco");
		diasMes = 31;
		break;
	case 4:
		printf("abril");
		diasMes = 30;
		break;
	case 5:
		printf("maio");
		diasMes = 31;
		break;
	case 6:
		printf("junho");
		diasMes = 30;
		break;
	case 7:
		printf("julho");
		diasMes = 31;
		break;
	case 8:
		printf("agosto");
		diasMes = 31;
		break;
	case 9:
		printf("setembro");
		diasMes = 30;
		break;
	case 10:
		printf("outubro");
		diasMes = 31;
		break;
	case 11:
		printf("novembro");
		diasMes = 30;
		break;
	case 12:
		printf("dezembro");
		diasMes = 31;
		break;
	default:
		printf("opcao invalida");
		diasMes = 0;
		anular = 1;
		break;
	}

	if (anular != 1)
	{
		// DIAS DO MES
		printf(" %i ", diasMes);

		// ANO
		printf("%i", ano);
		if (biSex == 1)
		{
			printf(" bissexto");
		}
	}

    return 0;
}

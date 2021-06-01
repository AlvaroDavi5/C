/*

Dizer se um Grupo de Pontos está ou não em uma Reta aX + b = Y

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int verifP1(int a, int b, int x1, int y1);
int verifP2(int a, int b, int x2, int y2);
int verifP3(int a, int b, int x3, int y3);

int main()
{
	int a, b;
	int x1, y1;
	int x2, y2;
	int x3, y3;
	int verif;

	scanf("%d %d %i %i %i %i %i %i", &a, &b, &x1, &y1, &x2, &y2, &x3, &y3);

	verif = verifP1(a, b, x1, y1) + verifP2(a, b, x2, y2) + verifP3(a, b, x3, y3);

	switch (verif)
	{
	case 1:
		printf("Um");
		break;
	case 2:
		printf("Dois");
		break;
	case 3:
		printf("Todos");
		break;
	default:
		printf("Nenhum");
		break;
	}

	return 0;
}

int verifP1(int a, int b, int x1, int y1)
{
	if ((a*x1 + b) == y1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int verifP2(int a, int b, int x2, int y2)
{
	if ((a*x2 + b) == y2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int verifP3(int a, int b, int x3, int y3)
{
	if ((a*x3 + b) == y3)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

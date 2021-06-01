// by Alvaro Davi, Eng Comp, UFES, 2020

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ehLetra(char c1, char c2, char c3);
int ehNumero(char n1, char n2, char n3, char n4);

int main()
{
	char c1, c2, c3;
	char n1, n2, n3, n4;
	int verif, letrV, numV;

	scanf("%c%c%c-%c%c%c%c", &c1, &c2, &c3, &n1, &n2, &n3, &n4);

	letrV = ehLetra(c1, c2, c3);
	numV = ehNumero(n1, n2, n3, n4);
	verif = letrV + numV;

	if (verif == 7)
		printf("Codigo valido!");
	else
	{
		printf("Codigo invalido!");
		if (letrV != 3 && numV == 4)
			printf("Problema nas letras!");
		if (numV != 4 && letrV == 3)
			printf("Problema nos numeros!");
		if (letrV != 3 && numV != 4)
			printf("Problema nas letras e nos numeros!");
	}

	return 0;
}

int ehLetra(char c1, char c2, char c3)
{
	int qtd = 0;

	if ((c1 >= 'a' && c1 <= 'z') || (c1 >= 'A' && c1 <= 'Z'))
	{
		qtd++;
	}
	if ((c2 >= 'a' && c2 <= 'z') || (c2 >= 'A' && c2 <= 'Z'))
	{
		qtd++;
	}
	if ((c3 >= 'a' && c3 <= 'z') || (c3 >= 'A' && c3 <= 'Z'))
	{
		qtd++;
	}
	else
	{
		qtd = 0;
	}

	return qtd;
}

int ehNumero(char n1, char n2, char n3, char n4)
{
	int qtd = 0;

	if (n1 >= '0' && n1 <= '9')
	{
		qtd++;
	}
	if (n2 >= '0' && n2 <= '9')
	{
		qtd++;
	}
	if (n3 >= '0' && n3 <= '9')
	{
		qtd++;
	}
	if (n4 >= '0' && n4 <= '9')
	{
		qtd++;
	}
	else
	{
		qtd = 0;
	}

	return qtd;
}

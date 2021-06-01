/*

Verificar quadrante de um ponto

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>

int main()
{
	float x, y;
	int quad;

	scanf("%f %f", &x, &y);

	/*
	QUADRANTES: 1 = (++), 2 = (-+), 3 = (--), 4 = (+-)
	EIXOS: (0,+), (0,-), (+,0), (-,0)
	ORIGEM: (0,0)
	*/

	if (x != 0 && y == 0)
	{
		printf("X");
	}
	else if (x == 0 && y != 0)
	{
		printf("Y");
	}

	else if (x == 0 && y == 0)
	{
		printf("ORIGEM");
	}

	else
	{
		if (x > 0 && y > 0)
		{
			printf("1");
		}
		else if (x < 0 && y > 0)
		{
			printf("2");
		}
		else if (x < 0 && y < 0)
		{
			printf("3");
		}
		else if (x > 0 && y < 0)
		{
			printf("4");
		}
	}

	return 0;
}
// by Alvaro Davi, Eng Comp, UFES, 2020

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	float peso, altura;
	float imc;

	scanf("%f %f", &peso, &altura);

	imc = peso / (altura*altura);

	printf("%.2f", imc);

	return 0;
}

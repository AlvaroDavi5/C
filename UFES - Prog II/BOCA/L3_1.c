/*

Realizar as 4 operções aritméticas

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>

float Soma(float num1, float num2);
float Subtracao(float num1, float num2);
float Divisao(float num1, float num2);
float Multiplicacao(float num1, float num2);

int main()
{
	float num1, num2;

	while ( scanf("%f %f", &num1, &num2) == 2 )
	{
		float result;

		result = Soma(num1, num2);
		printf("%.2f", result);
		result = Subtracao(num1, num2);
		printf(" %.2f", result);
		result = Divisao(num1, num2);
		printf(" %.2f", result);
		result = Multiplicacao(num1, num2);
		printf(" %.2f\n", result);
	}

	return 0;
}

float Soma(float num1, float num2)
{
	float res = (num1 + num2);
	return res;
}

float Subtracao(float num1, float num2)
{
	float res = (num1 - num2);
	return res;
}

float Divisao(float num1, float num2)
{
	float res = (num1 / num2);
	return res;
}

float Multiplicacao(float num1, float num2)
{
	float res = (num1 * num2);
	return res;
}


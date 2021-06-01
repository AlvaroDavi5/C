/*

Realizar as 4 operções aritméticas de acordo com a ordem operando >> operador

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <stdlib.h>

// ------------------------------------ FUNCOES ------------------------------------

float Soma(float num1, float num2)
{
	float res;
	res = (num1 + num2);
	return res;
}

float Subtracao(float num1, float num2)
{
	float res;
	res = (num1 - num2);
	return res;
}

float Divisao(float num1, float num2)
{
	float res;
	res = (num1 / num2);
	return res;
}

float Multiplicacao(float num1, float num2)
{
	float res;
	res = (num1 * num2);
	return res;
}

// ------------------ PRINCIPAL ------------------

int main()
{
	float num1, num2, num3, result;
	char operador;

	scanf("%f %f %c", &num1, &num2, &operador);

	switch(operador)
	{
		case '+':
			result = Soma(num1, num2);
			break;
		case '-':
			result = Subtracao(num1, num2);
			break;
		case '*':
			result = Multiplicacao(num1, num2);
			break;
		case '/':
			result = Divisao(num1, num2);
			break;
		default:
			break;
    }

	while (scanf("%f %c", &num3, &operador) == 2)
	{
		switch(operador)
		{
			case '+':
				result = Soma(result, num3);
				break;
			case '-':
				result = Subtracao(result, num3);
				break;
			case '*':
				result = Multiplicacao(result, num3);
				break;
			case '/':
				result = Divisao(result, num3);
				break;
			default:
				break;
		}
	}

	printf("%.2f", result);

	return 0;
}
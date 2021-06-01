/*

Calcular somatorio de (i / k)

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <math.h>

int main()
{
	int sit, expo;
	double i, k, pot, result;

	scanf("%d", &sit);

	switch (sit)
	{
		case 1:
			i = 1.00;
			k = 1.00;
			while (k <= 50)
			{
				result += (i / k);
				i += 2.00;
				k += 1.00;
			}
			break;
		case 2:
			i = 2.00;
			expo = 1;
			k = 50.00;
			while (k >= 1)
			{
				pot = pow(i, expo);
				result += (pot / k);
				expo++;
				k--;
			}
			break;
		case 3:
			i = 1.00;
			k = 1.00;
			while (k <= 100)
			{
				result += (i / k);
				i += 1.00;
				k = pow(i, 2);
			}
			break;
		default:
			break;
	}

	printf("%.6f", result);

	return 0;
}
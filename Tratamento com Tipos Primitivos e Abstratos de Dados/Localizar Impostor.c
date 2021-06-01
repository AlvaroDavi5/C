/*

Verificar impostor

Alvaro Davi, Eng Comp UFES, 2020

*/

//				~~~~~~ CREWMATE ~~~~~~
//			There is 1 impostor amon9 us 

#include <stdio.h>
#include <math.h>

int main()
{
	int num;
	int n1, n2, n3, n4;
	int algU, algD, algC, algM;

	scanf("%i", &num);

	for (int i = 0; i <= 100; i++)
	{
		algU = (num % 10);
		algD = (num % 100)/10;
		algC = (num % 1000)/100;
		algM = (num % 10000)/1000;

		if (num == 1)
		{
			break;
		}

		else if (num >= 0 && num < 10)
		{
			n1 = algU;

			n1 = n1 * n1;

			num = n1;
		}

		else if (num >= 10 && num < 100)
		{
			n1 = algU;
			n2 = algD;

			n1 = n1 * n1;
			n2 = n2 * n2;

			num = n1 + n2;
		}

		else if (num >= 100 && num < 1000)
		{
			n1 = algU;
			n2 = algD;
			n3 = algC;

			n1 = n1 * n1;
			n2 = n2 * n2;
			n3 = n3 * n3;

			num = n1 + n2 + n3;
		}

		else if (num >= 1000 && num < 10000)
		{
			n1 = algU;
			n2 = algD;
			n3 = algC;
			n4 = algM;

			n1 = n1 * n1;
			n2 = n2 * n2;
			n3 = n3 * n3;
			n4 = n4 * n4;

			num = n1 + n2 + n3 + n4;
		}

		else /* if (num < 0 || num >= 10000) */
		{
			printf("VALOR DEMASIADO PEQUENO/GRANDE");
		}
	}

	if (num == 1)
	{
		// printf("%d \n", num);
		printf("SIM");
	}

	else
	{
		// printf("%d \n", num);
		printf("NAO");
	}

	return 0;
}
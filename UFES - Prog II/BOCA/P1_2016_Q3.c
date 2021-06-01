/*

Verificar a validade de um código de 4 caracteres
O PRIMEIRO caractere deve ser maiúsculo; O SEGUNDO, um dígito; O TERCEIRO, uma vogal e o QUARTO uma consoante minúscula.

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int verifChar(char c1, int n2, char c3, char c4);
char toUpper(char charac);

int main()
{
	int n2;
	char c1, c3, c4; 
	scanf("%c%d%c%c", &c1, &n2, &c3, &c4);

	verifChar(c1, n2, c3, c4);

	return 0;
}

int verifChar(char c1, int n2, char c3, char c4)
{
	// VERIFICAR SE c1 ESTA EM MAIUSCULO
	if (c1 >= 'A' && c1 <= 'Z')
	{

		// VERIFICAR SE n2  E UM DIGITO NUMERICO (ALGARISMO)
		if (n2 >= 0 && n2 <= 9)
		{

			// VERIFICAR SE c3 E UMA VOGAL
			if ((c3 == 'a' || c3 == 'e' || c3 == 'i' || c3 == 'o' || c3 == 'u') || (c3 == 'A' || c3 == 'E' || c3 == 'I' || c3 == 'O' || c3 == 'U'))
			{
				c3 = toUpper(c3);

				// VERIFICAR SE c4 E UMA CONSOANTE MINUSCULA
				if ((c4 >= 'a' && c4 <= 'z') && (c4 != 'a' && c4 != 'e' && c4 != 'i' && c4 != 'o' && c4 != 'u'))
				{
					c4 = toUpper(c4);
					printf("%c%d%c%c", c1, n2, c3, c4);
				}
				else
				{
					printf("Invalido");
				}
			}
			else
			{
				printf("Invalido");
			}
		}
		else
		{
			printf("Invalido");
		}
	}
	else
	{
		printf("Invalido");
	}

	return 0;
}

char toUpper(char charac)
{
	if (charac >= 'a' && charac <= 'z')
	{
		charac -= 32; 
		return charac;
	}
	if (charac >= 'A' && charac <= 'Z')
	{
		return charac;
	}
}
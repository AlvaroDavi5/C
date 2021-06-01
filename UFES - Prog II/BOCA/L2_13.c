/*

Substituir letras minusculas por maiusculas

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>

int main()
{
	char letra;

	scanf("%c", &letra);

	while (1)
	{
		if (letra == '.' || letra == '!' || letra == '?')
		{
			if (letra == '.')
			{
				printf(".");
			}
			if (letra == '!')
			{
				printf("!");
			}
			if (letra == '?')
			{
				printf("?");
			}
			break;
		}

		else
		{
			if (letra >= 'a' && letra <= 'z')
			{
				letra = letra + (- 'a' + 'A'); // A diferenca entre maiusculas e minusculas da tabela ASCII é 32 ('A' - 'a')
				printf("%c", letra);
			}
			else
			{
				printf("%c", letra);
			}
		}
		scanf("%c", &letra);
	}

	return 0;
}
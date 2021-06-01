/*

Remover espaços

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>

int main()
{
	char letra;

	scanf("%c", &letra);
	printf("RESP:");

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
			if (letra == ' ')
			{
				printf("");
			}
			if (letra != ' ')
			{
				printf("%c", letra);
			}
		}
		scanf("%c", &letra);
	}

	return 0;
}
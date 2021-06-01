#include <stdio.h>
#include <stdlib.h>


void toBinary(int n);


int main()
{
	int num = 0;

	printf("Digite um numero inteiro em decimal: ");
	scanf("%d", &num);
	printf("\n \n");

	printf("Binário: "); toBinary(num);
	printf("Decimal: %d \n", num);
	printf("Octal: %o \n", num);
	printf("Hexadecimal: %x \n", num);

	return 0;
}

void toBinary(int n)
{
	int k = 0;

	for (int c = 15; c >= 0; c--)
	{
		k = n >> c;

		if (k & 1)
			printf("1");
		else
			printf("0");
	}

	printf("\n");
}

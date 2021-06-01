/*

Verificar se numero e primo

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;

	scanf("%d", &num);

	if((num % 2 != 0) && (num % 3 != 0) && (num % 5 != 0) && (num % 7 != 0) || (num == 2) || (num == 3) || (num == 5) || (num == 7))
	{
		printf("Primo");
	}

	else
	{
		printf("Nao primo");
	}

  return 0;
}
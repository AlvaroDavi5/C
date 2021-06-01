/*

O MMC entre 3 e 5 é 15, portanto só múltiplos de 15 serão divisíveis.

*/

#include<stdio.h>
#include<math.h>
 
int main()
{

	int numero;
 
	scanf("%d",&numero);
 
	if ((numero % 5 == 0) && (numero % 3 == 0))
	{
		printf("O número é divisível\n");
	}

	else
	{
		printf("O número não é divisível\n");
	}

	return 0;
}
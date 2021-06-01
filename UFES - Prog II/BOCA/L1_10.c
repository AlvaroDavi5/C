/*

Verificar se é par ou ímpar

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <math.h>

int main()
{
    int Num;

    scanf("%d", &Num);

	if (Num % 2 != 0)
	{
	    printf("Impar");
	}

	else
    {
    	printf("Par");
    }

    return 0;
}
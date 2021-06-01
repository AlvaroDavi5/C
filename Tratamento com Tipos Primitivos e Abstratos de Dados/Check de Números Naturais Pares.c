/*
ler Num
	Se Num % 2 != 0
		mostrar: "É Ímpar"
	Se não
		mostrar: "Não é Ímpar, é Par"
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int Num, Const;

	Const = 5;

    do
    {
		printf("Digite um número... \n");
    	scanf("%d", &Num);

		if (Num % 2 != 0)
		{
			printf("É Ímpar! \n");
		}

		else
    	{
    		printf("É Par. \n");
    	}

    }while (Const < 1000);

    return 0;
}
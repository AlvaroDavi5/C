#include <stdio.h>
#include <stdlib.h>


// nao sao funcionalidades padrao da linguagem C
int main()
{
	char letra = 'c';
	__try
	{
		printf("%s \n", letra);
	}
	__except
	{
		printf("Deu erro!!! \n");
	}
	__finally
	{
		printf("Saindo! \n");
	}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int option;

	int l = 12;
	int *j = &l; //o ponteiro j recebe o endereço de l
	int k = 27;
	int *p = &k; //o ponteiro p recebe o endereço de k

	printf("Ser quiser ver os endereços ocupados na memória digite '1' \nSe quiser ver algumas operações com ponteiros digite '2' \nPara cancelar digite qualquer outro valor...\n");
	scanf("%d", &option);

	if (option == 1)
	{
		printf("\nO valor de 'l' é: %i\nE ocupa o endereço: %p na memória; \n\n O valor de 'k' é: %i\nE ocupa o endereço: %p na memória.\n", l, j, k, p);
	}
	
	else if(option == 2)
	{
		printf("\nA variável 'p' é um ponteiro de 'k', ela armazena o endereço de 'k' na memória, logo: \n\nO valor que 'p' aponta é o mesmo valor que 'k' recebe: %i; \nO valor de 'p' é: %p, o endereço de 'k' na memória; \nO endereço de 'p' na memória é: %p.\n", *p, p, &p);
	}

	else // option != 1 && option != 2
	{
		printf("Encerrando programa...");
	}

	
	return 0;
}
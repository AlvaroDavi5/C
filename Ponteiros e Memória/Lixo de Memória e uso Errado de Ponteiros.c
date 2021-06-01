#include <stdio.h>
#include <stdlib.h>


int main()
{
	char num[5];
	int *p, *ptr = 0, *pointer = NULL;

	// uso incorreto
	printf("A variavel 'num' foi declarada sem uma string inicializada, logo seu conteudo sera o lixo de memoria: %s \n", num);
	printf("O ponteiro 'p' foi declarado sem um endereco inicializado, logo seu conteudo sera o endereco de uma variavel nao declarada: %p \n", p);

	// uso correto
	printf("O ponteiro 'ptr' foi declarado com o valor 0, logo seu conteudo sera o endereco: %p \n", ptr);
	printf("O ponteiro 'pointer' foi declarado com o valor NULL, logo seu conteudo sera o endereco: %p \n", pointer);

	return 0;
}

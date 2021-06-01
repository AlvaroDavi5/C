// Ponteiros armazenam endereços de memória de outras variáveis

#include <stdio.h>


int main()
{
	// Declaração de variável e ponteiro
	int ano, *pAno;

	// Inicialização
	ano = 2020;
	pAno = &ano; // Referência à 'ano'


	printf("ano value = %d \n", ano);
	// O valor decimal de 'ano'

	printf("ano value = %d \n", *&ano);
	// O valor decimal de 'ano' referenciado pelo seu próprio endereço

	printf("ano value = %d \n \n", *pAno);
	// O valor decimal de 'ano' referenciado pelo seu endereço armazenado em 'pAno'


	printf("ano adrres -> %p \n", &ano);
	// O endereço de 'ano'

	printf("ano adrres -> %p \n \n", pAno);
	// O endereço de 'ano' armazenado pelo ponteiro 'pAno'


	printf("pAno unsig dec adrres -> %u \n", &pAno);
	// O endereço de 'pAno' em decimal nao-assinado
	printf("pAno signed dec adrres -> %d \n", &pAno);
	// O endereço de 'pAno' em decimal assinado
	
	printf("pAno oct adrres -> %o \n", &pAno);
	// O endereço de 'pAno' em octal

	printf("pAno hex adrres -> %x \n \n", &pAno);
	// O endereço de 'pAno' em hexadecimal


	printf("pAno adrres -> %p \n", &pAno);
	// O endereço do ponteiro 'pAno'

	pAno = NULL;
	printf("pAno null adrres -> %p \n", pAno);
	// O ponteiro 'pAno' e apontado para o vazio

	return 0;
}

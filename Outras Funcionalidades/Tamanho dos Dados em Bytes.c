#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Tamanho de um inteiro: %lu bytes\n", sizeof(int));
	printf("Tamanho de um inteiro nao-assinado: %lu bytes\n", sizeof(unsigned int));
	printf("Tamanho de um inteiro longo: %lu bytes\n", sizeof(long int));
	printf("Tamanho de um real: %lu bytes\n", sizeof(float));
	printf("Tamanho de um real longo em casas decimais: %lu bytes\n", sizeof(double));
	printf("Tamanho de um caractere: %lu byte\n", sizeof(char));
	printf("Tamanho do vazio: %lu byte\n", sizeof(void));
	printf("Tamanho de um ponteiro para inteiro: %lu bytes\n", sizeof(int *));
	printf("Tamanho de um ponteiro para real: %lu bytes\n", sizeof(float *));
	printf("Tamanho de um ponteiro para caractere: %lu bytes\n", sizeof(char *));
	printf("Tamanho de um ponteiro para o vazio: %lu bytes\n", sizeof(void *));

	return 0;
}

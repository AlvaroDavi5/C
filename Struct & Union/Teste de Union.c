#include <stdio.h>
#include <math.h>


typedef struct
{
	int idade;
	float nota;
	char *matricula;
} tEstudante;

typedef union /* tipo complexo, o union é um tipo que sozinho não pode ser usado como tipificador de variáveis, para fazê-lo se utiliza o typedef */
{
	int idade;
	float nota;
	char *matricula; // tipos primitivos compondo o union
} tAluno; // em uma união, todos os membros compartilham a mesma locação de memória


int main()
{
	printf("Criados struct tEstudante e union tAluno.\n\n");
	printf("Tamanho do struct: %lu \nTamanho do union: %lu\n", sizeof(tEstudante), sizeof(tAluno));

	printf("\nPois o struct soma o tamanho em bytes de todos os atributos, enquanto o union pega apenas o do maior.\n\n");

	printf("sizeof int + float + char *: %lu + %lu + %lu \n", sizeof(int), sizeof(float), sizeof(char *));
	printf("sizeof int & float & char *: %lu \n", sizeof(char *));

	return 0;
}

#include <stdio.h>
#include <math.h>


typedef float real; // atribui o nome 'real' para o novo tipo definido com base no tipo float (em escopo global)

struct myStruct // cria struct chamada 'myStruct'
{
	int num;
	char letra;
};
typedef struct myStruct mystruct_t; // atribui tipo 'mystruct_t' a struct 'myStruct'


int main()
{
	real num;
	mystruct_t st1;

	st1.num = 15;
	st1.letra = 'A';

	scanf("%f", &num);
	printf("%.4f\n", num);
	printf("%d, %c", st1.num, st1.letra);

	return 0;
}

/*

 ALUNO: Alvaro Davi S. Alves (2020101874)

 DISCIPLINA: Estrutura de Dados I
 PROF: Patricia D. costa

 CURSO: Engenharia da Computacao
 Universidade Federal do Espirito Santo (UFES)

*/

#include <stdio.h>
#include <stdlib.h>


// prototypes
void assignValue(int *int_pointer, int value);
void increment(int *int_pointer);
void decrement(int *int_pointer);
void sum(int *p1, int *p2, int *res_pointer);
void subtract(int *p1, int *p2, int *res_pointer);
void multiply(int *pointer, float scalar);
void divide(int *pointer, float scalar);
void show(int *int_pointer);


int main()
{
	int intOne=0, intTwo=0, intThree=0, intFour=0, *piOne=NULL, *piTwo=NULL, *piThree=NULL, *piFour=NULL;

	// assigning values to pointers
	piOne = &intOne;
	piTwo = &intTwo;
	piThree = &intThree;
	piFour = &intFour;

	// operations
	increment(piOne);
	show(piOne);
	multiply(piOne, 5);
	show(piOne);
	decrement(piTwo);
	show(piTwo);
	sum(piOne, piTwo, piFour);
	show(piFour);
	subtract(piTwo, piOne, piThree);
	show(piThree);
	divide(piThree, 2.5);
	show(piThree);

	return 0;
}


void increment(int *int_pointer)
{
	*(int_pointer) += 1;
}

void decrement(int *int_pointer)
{
	*(int_pointer) -= 1;
}

void sum(int *p1, int *p2, int *res_pointer)
{
	*(res_pointer) = *(p1) + *(p2);
}

void subtract(int *p1, int *p2, int *res_pointer)
{
	*(res_pointer) = *(p1) - *(p2);
}

void multiply(int *pointer, float scalar)
{
	*(pointer) = *(pointer) * scalar;
}

void divide(int *pointer, float scalar)
{
	*(pointer) = *(pointer) / scalar;
}

void assignValue(int *int_pointer, int value)
{
	*(int_pointer) = value;
}

void show(int *int_pointer)
{
	printf("%d \n", *int_pointer);
}


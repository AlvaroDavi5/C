/*

 ALUNO: Alvaro Davi S. Alves (2020101874)

 DISCIPLINA: Estrutura de Dados I
 PROF: Patricia D. costa

 CURSO: Engenharia da Computacao
 Universidade Federal do Espirito Santo (UFES)

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// macros and constants
#define TRUE 1
#define FALSE 0
float Pi = 3.14159265359;

// functions prototypes
void calcSphere(float ray, float* area, float* volume);
int roots(float a, float b, float c, float* x1, float* x2);
int pairs(int size, int* arr);
void reverse(int size, int* arr);
double evaluate(double* poly, int degree, double x);
void safeFree(int* pointer);
void fillArray(int size, int* arr);
void printArray(int arr[], int size);


int main()
{
	// Sphere Area and Volume
	float r = 5.7, area = 0, volume = 0, *ptr_area = NULL, *ptr_vol = NULL;
	ptr_area = &area;
	ptr_vol = &volume;
	calcSphere(r, ptr_area, &volume);
	printf("Area: %f \t Volume:  %f \n", *ptr_area, *ptr_vol);

	// Equation Roots
	float a = -2, b = 5, c = 3, val1 = 0, val2 = 0, *x1 = NULL, *x2 = NULL;
	x1 = &val1;
	x2 = &val2;
	if(roots(a, b, c, x1, x2))
		printf("X' = %f \t X'' = %f \n", *x1, *x2);
	else
	{
		printf("ERROR: can't be exist squareroot of a negative number in set of Real Numbers! \n");
		exit(1);
	}

	// Pairs of Array
	int n1 = 5, *array1 = NULL;
	array1 = (int *) malloc(n1 * sizeof(int));
	fillArray(n1, array1);
	printf("Number of pairs: %d \n", pairs(n1, array1));
	safeFree(array1);

	// Reverse Array
	int j = 0, n2 = 10, *array2;
	array2 = (int *) malloc(n2 * sizeof(int));
	fillArray(n2, array2);
	reverse(n2, array2);
	safeFree(array2);

	// Polynomials
	int dg = 2;
	double x = 5, *poly = NULL;
	poly = (double *) malloc((dg+1) * sizeof(double));
	*(poly+0) = 12;
	*(poly+1) = 2;
	*(poly+2) = 3;
	printf("Value of polynomial: %f \n", evaluate(poly, dg, x));
	free(poly);

	return 0;
}


void calcSphere(float ray, float* area, float* volume)
{
	*(area) = 4*Pi * pow(ray, 2);

	*(volume) = (4*Pi * pow(ray, 3)) / 3;
}

int roots(float a, float b, float c, float* x1, float* x2)
{
	float delta = pow(b, 2) - 4*a*c;

	if (delta < 0)
	{
		return FALSE;
	}
	else
	{
		*(x1) = (-b + sqrt(delta)) / (2*a);
		*(x2) = (-b - sqrt(delta)) / (2*a);

		return TRUE;
	}
}

int pairs(int size, int* arr)
{
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		if (*(arr + i) % 2 == 0)
			count += 1;
	}

	return count;
}

void reverse(int size, int* arr)
{
	int i, aux;

	for (i = 0; i < size/2; i++)
	{
		aux = arr[i];
		arr[i] = arr[size - (i+1)];
		arr[size - (i+1)] = aux;
	}

	printArray(arr, size);
}

// Polynomial Evaluation
double evaluate(double* poly, int degree, double x)
{
	double result = 0;

	for (int i = degree; i >= 0; i--)
	{
		result += *(poly + i) * pow(x, i);
	}

	return result;
}

void safeFree(int* pointer)
{
	if (pointer != NULL)
	{
		*(pointer) = 0.00;
		free(pointer);
		pointer = NULL;
	}
}

void fillArray(int size, int* arr)
{
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = i+1;
	}

	printArray(arr, size);
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d", arr[i]);

		if (i < (size - 1))
			printf(", ");
	}
	printf("\n");
}


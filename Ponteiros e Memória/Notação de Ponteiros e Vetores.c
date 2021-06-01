#include <stdio.h>
#include <stdlib.h>


int main()
{
	int vector[5] = {1, 2, 3, 4, 5};
	int *array = vector;

	printf("%d \n", vector[+1]);
	printf("%d \n", *(array + 1));
	printf("\n");

	printf("%p \n", vector);
	printf("%p \n", array);
	printf("\n");

	printf("%p \n", &vector[-2]);
	printf("%p \n", &array[-2]);
	printf("%p \n", array-2);
	printf("\n");

	printf("%p \n", &vector[-2]);
	printf("%p \n", &vector[-1]);
	printf("%p \n", &vector[0]);
	printf("%p \n", &vector[1]);
	printf("%p \n", &vector[2]);
	printf("\n");

	return 0;
}


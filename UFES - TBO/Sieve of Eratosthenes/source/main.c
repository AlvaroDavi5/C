// Sieve of Eratosthenes
#include <stdio.h>
#include <stdlib.h>
#include "../include/sieve_of_eratosthenes.h"
#include "../include/utils.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Expected 2 arguments but received %d arguments", argc);
		exit(1);
	}

	const int arraySize = (int)strtol(argv[1], NULL, 10);
	int *primeNumbers = NULL;

	primeNumbers = (int *)malloc(arraySize * sizeof(int));
	if (!wasAllocated(primeNumbers))
	{
		printf("primeNumbers allocation error!\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < arraySize; i++)
	{
		primeNumbers[i] = 0;
	}
	calcPrimeNumbers(primeNumbers, arraySize);

	safeFree(primeNumbers);

	return 0;
}

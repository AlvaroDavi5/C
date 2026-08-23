// Sieve of Eratosthenes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/sieve_of_eratosthenes.h"
#include "../include/utils.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Expected 2 arguments but received %d arguments", argc);
		exit(1);
	}

	const int arraySize = (int)atoi(argv[1]);
	int *primeNumbersV1 = NULL;
	int *primeNumbersV2 = NULL;
	struct timespec startV1, startV2;
	TimeElapsed elapsedV1, elapsedV2;

	primeNumbersV1 = (int *)allocateArray(arraySize, sizeof(int));
	if (!wasAllocated(primeNumbersV1))
	{
		printf("primeNumbersV1 allocation error!\n");
		exit(EXIT_FAILURE);
	}

	primeNumbersV2 = (int *)allocateArray(arraySize, sizeof(int));
	if (!wasAllocated(primeNumbersV2))
	{
		printf("primeNumbersV2 allocation error!\n");
		safeFree(primeNumbersV1);
		exit(EXIT_FAILURE);
	}

	printf("=== Sieve of Eratosthenes Efficiency Comparison ===\n");
	printf("Array size: %d\n\n", arraySize);

	startV1 = getTimeStart();
	calcPrimeNumbersV1(primeNumbersV1, arraySize);
	elapsedV1 = getTimeElapsed(startV1);

	printf("Algorithm V1:\n");
	printf("Time: %ld.%03ld seconds\n", elapsedV1.seconds, elapsedV1.milliseconds);
	printPrimeNumbers(primeNumbersV1, arraySize);

	printf("\n");

	startV2 = getTimeStart();
	calcPrimeNumbersV2(primeNumbersV2, arraySize);
	elapsedV2 = getTimeElapsed(startV2);

	printf("Algorithm V2:\n");
	printf("Time: %ld.%03ld seconds\n", elapsedV2.seconds, elapsedV2.milliseconds);
	printPrimeNumbers(primeNumbersV2, arraySize);

	printf("\n=== Performance Comparison ===\n");
	long totalMillisV1 = (elapsedV1.seconds * 1000) + elapsedV1.milliseconds;
	long totalMillisV2 = (elapsedV2.seconds * 1000) + elapsedV2.milliseconds;
	printf("V1 Total: %ld ms\n", totalMillisV1);
	printf("V2 Total: %ld ms\n", totalMillisV2);

	safeFree(primeNumbersV1);
	safeFree(primeNumbersV2);

	return 0;
}

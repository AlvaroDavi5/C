#include "../include/sieve_of_eratosthenes.h"

bool isMultiple(int number, int base)
{
	return number % base == 0;
}

void calcPrimeNumbersV1(int *numList, const int arrSize)
{
	int num = 2; // two is the first possible prime number

	// populate number list
	for (int k = 0, num = 2; num <= arrSize; num++, k++)
	{
		numList[k] = num;
	}

	bool wasRemoved = false;
	for (int i = 0; i < arrSize; i++)
	{
		wasRemoved = false;
		if (numList[i] == REMOVED_NUMBER)
		{
			continue;
		}
		num = numList[i];

		// remove prime number multiples
		for (int j = i + 1; j < arrSize; j++)
		{
			if (numList[j] != REMOVED_NUMBER && isMultiple(numList[j], num))
			{
				numList[j] = REMOVED_NUMBER;
				wasRemoved = true;
			}
		}

		if (wasRemoved == false)
		{
			// break;
		}
	}
}

void calcPrimeNumbersV2(int *numList, const int arrSize)
{
	const int maxCheckedNumber = floor(sqrt(arrSize));
	int num = 2; // two is the first possible prime number

	// populate number list
	for (int k = 0, num = 2; num <= arrSize; num++, k++)
	{
		numList[k] = num;
	}

	bool wasRemoved = false;
	for (int i = 0; i < arrSize; i++)
	{
		wasRemoved = false;
		if (numList[i] == REMOVED_NUMBER)
		{
			continue;
		}
		num = numList[i];

		// remove prime number multiples
		for (int j = i + 1; j < arrSize; j++)
		{
			if (numList[j] != REMOVED_NUMBER && isMultiple(numList[j], num))
			{
				numList[j] = REMOVED_NUMBER;
				wasRemoved = true;
			}
		}

		if (wasRemoved == false || numList[i] == maxCheckedNumber)
		{
			// break;
		}
	}
}

void printPrimeNumbers(int *numList, const int arrSize)
{
	unsigned int primeCount = 0;
	for (int i = 0; i < arrSize; i++)
	{
		if (numList[i] != REMOVED_NUMBER)
			primeCount++;
	}

	printf("Prime List (count = %d/%d):\n", primeCount, arrSize);
	for (int i = 0; i < arrSize; i++)
	{
		int num = numList[i];

		if (num != REMOVED_NUMBER)
			printf("%d, ", num);
	}
	printf("\nEND\n");
}
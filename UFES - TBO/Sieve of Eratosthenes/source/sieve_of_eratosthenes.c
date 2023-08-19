#include "../include/sieve_of_eratosthenes.h"

bool isMultiple(int n1, int n2)
{
	return n1 % n2 == 0;
}

void calcPrimeNumbers(int *numList, const int n)
{
	int maxCheckedNumber = floor(sqrt(n));
	int num = 2; // first prime number
	int size = 0;

	// populate number list
	for (num = 2; num <= n; num++, size++)
		numList[size] = num;

	int i = 0, removedCount = 0;
	bool wasRemoved = false;
	while (true)
	{
		wasRemoved = false;

		if (numList[i] != REMOVED_NUMBER)
		{
			num = numList[i];
		}
		else
		{
			i++;
			continue;
		}

		// remove prime number multiples
		for (int j = i + 1; j < size; j++)
		{
			if (isMultiple(numList[j], num))
			{
				numList[j] = REMOVED_NUMBER; // removed
				wasRemoved = true;
				removedCount++;
			}
		}
		if (wasRemoved == false || numList[i] == maxCheckedNumber)
			break;
		i++;
	}

	printf("Prime List:\n");
	for (int k = 0; k < n; k++)
	{
		if (numList[k] != REMOVED_NUMBER)
		{
			printf("%d\n", numList[k]);
		}
	}
}

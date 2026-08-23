#ifndef _SIEVE_H

	#define _SIEVE_H

	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include <math.h>

	#define REMOVED_NUMBER -999

	bool isMultiple(int n1, int n2);
	void calcPrimeNumbersV1(int *numList, const int arrSize);
	void calcPrimeNumbersV2(int *numList, const int arrSize);
	void printPrimeNumbers(int *numList, const int arrSize);

#endif

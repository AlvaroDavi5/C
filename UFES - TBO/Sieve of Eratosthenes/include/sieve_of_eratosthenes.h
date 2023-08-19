#ifndef _SIEVE_H

	#define _SIEVE_H

	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include <math.h>

	#define REMOVED_NUMBER -1

	bool isMultiple(int n1, int n2);
	void calcPrimeNumbers(int *numList, const int n);

#endif

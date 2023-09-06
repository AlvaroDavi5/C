#include "../include/utils.h"

void safeFree(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
	ptr = NULL;

	return;
}

bool wasAllocated(void *pointer)
{
	if (!pointer)
		return false;
	else
		return true;
}

void printTimeInterval(clock_t start, clock_t stop, char *msg)
{
	double timeInterval = ((double)stop - start) / CLOCKS_PER_SEC;
	printf("\n%s: %.5f\n", msg, timeInterval);
}

int getRandomValue()
{
	const int randomNumber = rand() % RAND_MAX;

	return randomNumber;
}

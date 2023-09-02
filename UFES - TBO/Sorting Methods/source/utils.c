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

Item *allocateItemsArray(Item *array, size_t size)
{
	array = (Item *)malloc(size * sizeof(Item));

	if (wasAllocated(array))
		return array;

	return NULL;
}

void printTimeInterval(clock_t start, clock_t stop, char *msg)
{
	double timeInterval = ((double)stop - start) / CLOCKS_PER_SEC;
	printf("\n%s: %.5f\n", msg, timeInterval);
}

void randomValues(Item *array, size_t size, int min, int max)
{
	for (size_t i = 0; i < size; i++)
	{
		*(array + i) = rand() % (max - min + 1) + min;
	}
}

void printArray(Item *array, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("%d, ", *(array + i));
	}
	printf("\n");
}

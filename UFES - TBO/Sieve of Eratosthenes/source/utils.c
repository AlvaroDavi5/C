#include "../include/utils.h"

void *allocateArray(unsigned int arraySize, unsigned long byteSize)
{
	return malloc(arraySize * byteSize);
}

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

struct timespec getTimeStart(void)
{
	struct timespec start;
	clock_gettime(CLOCK_MONOTONIC, &start);
	return start;
}

TimeElapsed getTimeElapsed(struct timespec start)
{
	struct timespec end;
	clock_gettime(CLOCK_MONOTONIC, &end);

	TimeElapsed elapsed;
	elapsed.seconds = end.tv_sec - start.tv_sec;
	elapsed.milliseconds = (end.tv_nsec - start.tv_nsec) / 1000000;

	if (elapsed.milliseconds < 0)
	{
		elapsed.seconds--;
		elapsed.milliseconds += 1000;
	}

	return elapsed;
}

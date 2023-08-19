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

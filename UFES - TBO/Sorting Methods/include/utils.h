#ifndef _UTILS_H

#define _UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "./item.h"

void safeFree(void *ptr);
bool wasAllocated(void *pointer);
Item *allocateItemsArray(Item *array, size_t size);
void printTimeInterval(clock_t start, clock_t stop, char *msg);
void randomValues(Item *array, size_t size, int min, int max);
void printArray(Item *array, size_t size);

#endif

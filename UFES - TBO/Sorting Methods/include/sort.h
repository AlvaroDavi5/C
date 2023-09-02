#ifndef _SORT_H

#define _SORT_H

#include <stdio.h>
#include <stdlib.h>
#include "./item.h"

void bubbleSort(Item *array, size_t size);
void selectionSort(Item *array, size_t size);
void insertionSort(Item *array, size_t size);
void quickSort(Item *array, size_t begin, size_t end);

#endif

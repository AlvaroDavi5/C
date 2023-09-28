#ifndef _SORT_H

#define _SORT_H

#include <stdio.h>
#include <stdlib.h>
#include "./item.h"

// O(N^2)
void bubbleSort(Item *array, size_t size);
// O(N^2)
void selectionSort(Item *array, size_t size);
// O(N^2)
void insertionSort(Item *array, size_t size);
// O(N * lg N)
void mergeSort(Item *array, size_t left, size_t right);
// O(N^2)
void shellSort(Item *array, size_t size);
// O(N * lg N)
void heapSort(Item *array, size_t size);
// O(N * lg N)
void quickSort(Item *array, size_t begin, size_t end);

#endif

// Sort Algorithms
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../include/item.h"
#include "../include/sort.h"
#include "../include/utils.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));
	clock_t start = clock(), stop = clock();

	if (argc < 3)
	{
		printf("Expected 3 arguments but received %d arguments", argc);
		exit(EXIT_FAILURE);
	}

	const size_t itemsAmount = (size_t)atoi(argv[1]);
	Item *bubbleSortArray = NULL, *selectionSortArray = NULL, *insertionSortArray = NULL;
	Item *mergeSortArray = NULL, *shellSortArray = NULL, *heapSortArray = NULL, *quickSortArray = NULL;
	bubbleSortArray = allocateItemsArray(bubbleSortArray, itemsAmount);
	selectionSortArray = allocateItemsArray(selectionSortArray, itemsAmount);
	insertionSortArray = allocateItemsArray(insertionSortArray, itemsAmount);
	mergeSortArray = allocateItemsArray(mergeSortArray, itemsAmount);
	shellSortArray = allocateItemsArray(shellSortArray, itemsAmount);
	heapSortArray = allocateItemsArray(heapSortArray, itemsAmount);
	quickSortArray = allocateItemsArray(quickSortArray, itemsAmount);

	if (bubbleSortArray == NULL ||
			selectionSortArray == NULL ||
			insertionSortArray == NULL ||
			mergeSortArray == NULL ||
			shellSortArray == NULL ||
			heapSortArray == NULL ||
			quickSortArray == NULL)
	{
		printf("Array allocation error!\n");
		exit(EXIT_FAILURE);
	}

	const char *useRand = argv[2];
	if (strcmp(useRand, "true") == 0)
	{
		randomValues(bubbleSortArray, itemsAmount, 0, itemsAmount * 2);
		randomValues(selectionSortArray, itemsAmount, 0, itemsAmount * 2);
		randomValues(insertionSortArray, itemsAmount, 0, itemsAmount * 2);
		randomValues(mergeSortArray, itemsAmount, 0, itemsAmount * 2);
		randomValues(shellSortArray, itemsAmount, 0, itemsAmount * 2);
		randomValues(heapSortArray, itemsAmount, 0, itemsAmount * 2);
		randomValues(quickSortArray, itemsAmount, 0, itemsAmount * 2);
	}
	else
	{
		for (size_t i = 0; i < itemsAmount; i++)
		{
			Item num = 0;
			scanf("%d", &num);
			*(bubbleSortArray + i) = num;
			*(selectionSortArray + i) = num;
			*(insertionSortArray + i) = num;
			*(mergeSortArray + i) = num;
			*(shellSortArray + i) = num;
			*(heapSortArray + i) = num;
			*(quickSortArray + i) = num;
		}
	}

	// bubbleSort
	start = clock();
	bubbleSort(bubbleSortArray, itemsAmount);
	stop = clock();
	printTimeInterval(start, stop, "bubbleSort exec time");
	safeFree(bubbleSortArray);

	// selectionSort
	start = clock();
	selectionSort(selectionSortArray, itemsAmount);
	stop = clock();
	printTimeInterval(start, stop, "selectionSort exec time");
	safeFree(selectionSortArray);

	// insertionSort
	start = clock();
	insertionSort(insertionSortArray, itemsAmount);
	stop = clock();
	printTimeInterval(start, stop, "insertionSort exec time");
	safeFree(insertionSortArray);

	// mergeSort
	start = clock();
	mergeSort(mergeSortArray, 0, itemsAmount - 1);
	stop = clock();
	printTimeInterval(start, stop, "mergeSort exec time");
	safeFree(mergeSortArray);

	// shellSort
	start = clock();
	shellSort(shellSortArray, itemsAmount);
	stop = clock();
	printTimeInterval(start, stop, "shellSort exec time");
	safeFree(shellSortArray);

	// heapSort
	start = clock();
	heapSort(heapSortArray, itemsAmount);
	stop = clock();
	printTimeInterval(start, stop, "heapSort exec time");
	safeFree(heapSortArray);

	// quickSort
	start = clock();
	quickSort(quickSortArray, 0, itemsAmount - 1);
	stop = clock();
	printTimeInterval(start, stop, "quickSort exec time");
	safeFree(quickSortArray);

	return 0;
}

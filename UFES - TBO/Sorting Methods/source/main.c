// Sort Algorithms
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../include/item.h"
#include "../include/sort.h"
#include "../include/utils.h"

#define PRINT_ARRAY 0

int main(int argc, char *argv[])
{
	srand(time(NULL));
	clock_t start = clock(), stop = clock();

	if (argc < 3)
	{
		printf("Expected 3 arguments but received %d arguments", argc);
		exit(1);
	}

	const size_t itemsAmount = (size_t)atoi(argv[1]);
	Item *itemsArray = allocateItemsArray(itemsArray, itemsAmount);

	if (itemsArray == NULL)
	{
		printf("itemsArray allocation error!\n");
		exit(EXIT_FAILURE);
	}

	const char *useRand = argv[2];
	if (strcmp(useRand, "true") == 0)
	{
		randomValues(itemsArray, itemsAmount, 0, itemsAmount * 2);
	}
	else
	{
		for (size_t i = 0; i < itemsAmount; i++)
		{
			Item num = 0;
			scanf("%d", &num);
			*(itemsArray + i) = num;
		}
	}

	if (PRINT_ARRAY)
	{
		printf("Unsorted itemsArray:\n");
		printArray(itemsArray, itemsAmount);
	}

	start = clock();
	selectionSort(itemsArray, itemsAmount);
	stop = clock();
	printTimeInterval(start, stop, "SelectionSort Exec Time");

	if (PRINT_ARRAY)
	{
		printf("Sorted itemsArray:\n");
		printArray(itemsArray, itemsAmount);
	}

	safeFree(itemsArray);

	return 0;
}

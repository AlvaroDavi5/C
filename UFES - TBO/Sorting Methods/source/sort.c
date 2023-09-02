#include "../include/sort.h"

void bubbleSort(Item *array, size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < (size - i) - 1; j++)
		{
			compSwap(array[j], array[j + 1]);
		}
	}
}

void selectionSort(Item *array, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		size_t minUnsortedIndex = i;

		for (size_t j = i + 1; j < size; j++)
		{
			if (less(array[j], array[minUnsortedIndex]))
				minUnsortedIndex = j;
		}

		if (minUnsortedIndex != i)
			swap(array[i], array[minUnsortedIndex]);
	}
}

void insertionSort(Item *array, size_t size)
{
	for (size_t i = 1; i < size; i++)
	{
		Item memory = array[i];
		int j = i - 1;

		while ((j >= 0) && less(memory, array[j]))
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = memory;
	}
}

size_t _partition(Item *array, size_t begin, size_t end)
{
	size_t left, right;
	Item pivotElement;

	left = begin;
	right = end;
	pivotElement = array[begin];

	while (left < right)
	{
		while (array[left] <= pivotElement)
		{
			left++;
		}
		while (array[right] > pivotElement)
		{
			right--;
		}

		if (left < right)
			swap(array[left], array[right]);
	}
	array[begin] = array[right];
	array[right] = pivotElement;

	return right;
}

void quickSort(Item *array, size_t begin, size_t end)
{
	size_t pivot;

	if (end > begin)
	{
		pivot = _partition(array, begin, end);
		quickSort(array, begin, pivot - 1);
		quickSort(array, pivot + 1, end);
	}
}

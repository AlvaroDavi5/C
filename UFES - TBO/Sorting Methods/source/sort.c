#include "../include/sort.h"

// O(N^2)
void bubbleSort(Item *array, size_t size)
{
	for (size_t i = 0; i < size - 1; i++) // O(N)
	{
		for (size_t j = 0; j < (size - i) - 1; j++) // O(N-1) == O(N)
		{
			compSwap(array[j], array[j + 1]);
		}
	}
}

// O(N^2)
void selectionSort(Item *array, size_t size)
{
	for (size_t i = 0; i < size; i++) // O(N)
	{
		size_t minUnsortedIndex = i;

		for (size_t j = i + 1; j < size; j++) // O(N-1) == O(N)
		{
			if (less(array[j], array[minUnsortedIndex]))
				minUnsortedIndex = j;
		}

		if (minUnsortedIndex != i)
			swap(array[i], array[minUnsortedIndex]);
	}
}

// O(N^2)
void insertionSort(Item *array, size_t size)
{
	for (size_t i = 1; i < size; i++) // O(N)
	{
		Item memory = array[i];
		int j = i - 1;

		while ((j >= 0) && less(memory, array[j])) // O(N-1) == O(N)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = memory;
	}
}

// 3O(N) == O(N)
void _merge(Item *array, size_t left, size_t middle, size_t right)
{
	size_t i, j, k;
	size_t size1 = middle - left + 1;
	size_t size2 = right - middle;

	Item leftArray[size1], rightArray[size2];

	// 2O(N/2) == O(N)
	for (i = 0; i < size1; i++) // O(N/2)
		leftArray[i] = array[left + i];
	for (j = 0; j < size2; j++) // O(N/2)
		rightArray[j] = array[middle + 1 + j];

	i = 0;
	j = 0;
	k = left;
	while (i < size1 && j < size2) // O(N/2) + O(N/2) == 2O(N/2) == O(N)
	{
		if (leftArray[i] <= rightArray[j])
		{
			array[k] = leftArray[i];
			i++;
		}
		else
		{
			array[k] = rightArray[j];
			j++;
		}
		k++;
	}

	// 2O(N/2) == O(N)
	while (i < size1) // O(N/2)
	{
		array[k] = leftArray[i];
		i++;
		k++;
	}
	while (j < size2) // O(N/2)
	{
		array[k] = rightArray[j];
		j++;
		k++;
	}
}

// O(lg N) * O(N) == O(N * lg N)
void mergeSort(Item *array, size_t left, size_t right)
{
	if (left < right)
	{
		size_t middle = left + (right - left) / 2;

		// O(lg N)
		mergeSort(array, left, middle);
		mergeSort(array, middle + 1, right);

		_merge(array, left, middle, right); // O(N)
	}
}

// O(lg N) * O(N^2) == O(N^2)
void shellSort(Item *array, size_t size)
{
	for (size_t gap = size / 2; gap > 0; gap /= 2) // O(lg N)
	{
		for (size_t i = gap; i < size; i++) // O(N-1) == O(N)
		{
			size_t j;
			Item aux = array[i];

			for (j = i; j >= gap && array[j - gap] > aux; j -= gap) // O(N-1) == O(N)
			{
				array[j] = array[j - gap];
			}

			array[j] = aux;
		}
	}
}

// O(lg N)
void _heapify(Item *array, size_t size, size_t i)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < size && array[left] > array[largest])
		largest = left;
	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(array[i], array[largest]);
		_heapify(array, size, largest);
	}
}

// 2O(N * lg N) == O(N * lg N)
void heapSort(Item *array, size_t size)
{
	// O(lg N) * O(N/2) == O(N * lg N)
	for (int i = size / 2 - 1; i >= 0; i--) // O(N/2-1) == O(N/2)
		_heapify(array, size, i); // O(lg N)

	// O(lg N) * O(N) == O(N * lg N)
	for (size_t i = size - 1; i > 0; i--) // O(N-1) == O(N)
	{
		swap(array[0], array[i]);
		_heapify(array, i, 0); // O(lg N)
	}
}

// O(N)
size_t _partition(Item *array, size_t begin, size_t end)
{
	size_t pivotIndex = begin;
	Item pivotElement = array[end];

	for (size_t i = begin; i < end; i++) // O(N)
	{
		if (array[i] <= pivotElement)
		{
			swap(array[i], array[pivotIndex]);
			pivotIndex++;
		}
	}

	swap(array[pivotIndex], array[end]);

	return pivotIndex;
}

// O(N)
size_t _random_partition(Item *array, size_t begin, size_t end)
{
	size_t pivotIndex = (rand() % (end - begin + 1)) + begin; // O(1)

	swap(array[pivotIndex], array[end]);
	return _partition(array, begin, end); // O(N)
}

// O(lg N) * O(N) == O(N * lg N)
void quickSort(Item *array, size_t begin, size_t end)
{
	if (begin < end)
	{
		size_t pivotIndex = _random_partition(array, begin, end); // O(N)

		// O(lg N)
		quickSort(array, begin, pivotIndex - 1);
		quickSort(array, pivotIndex + 1, end);
	}
}

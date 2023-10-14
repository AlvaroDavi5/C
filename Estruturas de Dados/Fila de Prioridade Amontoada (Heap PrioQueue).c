#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>

struct event
{
	double timestamp;
	int value;
};
typedef struct event Event;

#define swap(A, B)  \
	{                 \
		Event *aux = A; \
		A = B;          \
		B = aux;        \
	}

struct priority_queue
{
	unsigned int size, actualSize;
	Event **eventsArray;
};
typedef struct priority_queue Heap;

double getTimestamp(clock_t start, clock_t stop);
Event *createEvent(int value, double timestamp);
void deleteEvent(Event *event);
Heap *createPrioQueue(unsigned int size);
void destroyPrioQueue(Heap *prioQueue);
void insert(Heap *prioQueue, Event *event);
Event *removeMin(Heap *prioQueue);
bool isFull(Heap *prioQueue);
bool isEmpty(Heap *prioQueue);

int main()
{
	srand(time(NULL));
	int op = 999;
	Heap *pq = createPrioQueue(50);
	clock_t start = clock();
	int value = 0;
	Event *newEvent = NULL, *minEvent = NULL;

	do
	{
		printf("\n------------- SELECT AN OPTION -------------\n");
		printf("0. Exit\n");
		printf("1. Insert\n");
		printf("2. Remove Min\n");
		printf("3. Is Empty\n");
		printf("4. Is Full\n");

		printf("\nType a number: ");
		scanf("%d", &op);

		switch (op)
		{
		case 0:
			destroyPrioQueue(pq);
			exit(0);
			break;
		case 1:
			printf("\nType a value: ");
			scanf("%d", &value);
			newEvent = createEvent(value, getTimestamp(start, clock()));
			insert(pq, newEvent);
			printf("\nInserted Event - value: %d, timestamp: %.5f\n", newEvent->value, newEvent->timestamp);
			break;
		case 2:
			minEvent = removeMin(pq);
			if (minEvent != NULL)
			{
				printf("\nRemoved Event - value: %d, timestamp: %.5f\n", minEvent->value, minEvent->timestamp);
				deleteEvent(minEvent);
			}
			else
				printf("\nPriority queue is empty\n");
			break;
		case 3:
			printf("\nIs empty: ");
			if (isEmpty(pq))
				printf("TRUE\n");
			else
				printf("FALSE\n");
			break;
		case 4:
			printf("\nIs full: ");
			if (isFull(pq))
				printf("TRUE\n");
			else
				printf("FALSE\n");
			break;
		default:
			printf("\nInvalid option!\n");
			break;
		}
	} while (op != 0);
}

double getTimestamp(clock_t start, clock_t stop)
{
	double timeInterval = ((double)stop - start) / CLOCKS_PER_SEC;
	return timeInterval;
}

Event *createEvent(int value, double timestamp)
{
	Event *event = (Event *)malloc(sizeof(Event));

	event->value = value;
	event->timestamp = timestamp;

	return event;
}

void deleteEvent(Event *event)
{
	if (event != NULL)
	{
		free(event);
		event = NULL;
	}
}

Heap *createPrioQueue(unsigned int size)
{
	Heap *prioQueue = (Heap *)malloc(sizeof(Heap));

	prioQueue->size = size;
	prioQueue->actualSize = 0;
	prioQueue->eventsArray = (Event **)malloc(size * sizeof(Event *));

	Event **eventsArray = prioQueue->eventsArray;
	for (size_t i = 0; i < size; i++)
		eventsArray[i] = NULL;

	return prioQueue;
}

void destroyPrioQueue(Heap *prioQueue)
{
	if (prioQueue != NULL)
	{
		if (prioQueue->eventsArray != NULL)
		{
			Event **eventsArray = prioQueue->eventsArray;
			for (size_t i = 1; i < prioQueue->actualSize + 1; i++)
				deleteEvent(eventsArray[i]);

			free(prioQueue->eventsArray);
			prioQueue->eventsArray = NULL;
		}

		free(prioQueue);
		prioQueue = NULL;
	}
}

int _compare(Event *a, Event *b)
{
	return a->value - b->value;
}

static void _heapifyUp(Heap *prioQueue, int key) // to be parent
{
	Event **eventsArray = prioQueue->eventsArray;
	while (key > 1 && _compare(eventsArray[key / 2], eventsArray[key]) > 0) // parent: k/2, children: 2k|2k+1
	{
		swap(eventsArray[key], eventsArray[key / 2]);
		key = key / 2;
	}
}

void insert(Heap *prioQueue, Event *event)
{
	if (prioQueue->actualSize >= prioQueue->size)
	{
		printf("Queue is full, exiting...\n");
		exit(EXIT_FAILURE);
	}

	prioQueue->actualSize++;
	prioQueue->eventsArray[prioQueue->actualSize] = event; // last heap element
	_heapifyUp(prioQueue, prioQueue->actualSize);
}

void _heapifyDown(Heap *prioQueue, int key) // to be children
{
	Event **eventsArray = prioQueue->eventsArray;
	while (2 * key <= prioQueue->actualSize)
	{
		int i = 2 * key;
		if (i < prioQueue->actualSize && _compare(eventsArray[i], eventsArray[i + 1]) > 0)
		{
			i++;
		}
		if (!(_compare(eventsArray[key], eventsArray[i]) > 0))
			break;
		swap(eventsArray[key], eventsArray[i]);
		key = i;
	}
}

Event *removeMin(Heap *prioQueue)
{
	if (isEmpty(prioQueue))
		return NULL;

	Event *event = prioQueue->eventsArray[1]; // first heap element

	prioQueue->eventsArray[1] = prioQueue->eventsArray[prioQueue->actualSize];
	prioQueue->eventsArray[prioQueue->actualSize] = NULL;
	prioQueue->actualSize--;
	_heapifyDown(prioQueue, 1);

	return event;
}

bool isFull(Heap *prioQueue)
{
	return (prioQueue->actualSize == prioQueue->size);
}

bool isEmpty(Heap *prioQueue)
{
	return (prioQueue->actualSize == 0);
}

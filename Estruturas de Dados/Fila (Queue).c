#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define Item int

struct queue
{
	int front, rear;
	unsigned int size, actualSize;
	Item *array;
};
typedef struct queue Queue; // Queue is a FIFO data structure

Queue *createQueue(unsigned int size);
void destroyQueue(Queue *queue);
bool isFull(Queue *queue);
bool isEmpty(Queue *queue);
void enqueue(Queue *queue, Item item);
Item dequeue(Queue *queue);
Item front(Queue *queue);
Item rear(Queue *queue);

int main()
{
	int op = 999, value = 0;
	Queue *my_queue = createQueue(50);

	do
	{
		printf("\n------------- SELECT AN OPTION -------------\n");
		printf("0. Exit\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Is Empty\n");
		printf("4. First Element\n");
		printf("5. Last Element\n");

		printf("\nType a number: ");
		scanf("%d", &op);

		switch (op)
		{
		case 0:
			destroyQueue(my_queue);
			exit(0);
			break;
		case 1:
			printf("\nType a value: ");
			scanf("%d", &value);
			enqueue(my_queue, value);
			printf("\nElement: %d enqueued\n", value);
			break;
		case 2:
			printf("\nElement: %d dequeued\n", dequeue(my_queue));
			break;
		case 3:
			printf("\nIs empty: ");
			if (isEmpty(my_queue))
				printf("TRUE\n");
			else
				printf("FALSE\n");
			break;
		case 4:
			printf("\nFirst element: %d\n", front(my_queue));
			break;
		case 5:
			printf("\nLast element: %d\n", rear(my_queue));
			break;
		default:
			printf("\nInvalid option!\n");
			break;
		}
	} while (op != 0);
}

Queue *createQueue(unsigned int size)
{
	Queue *queue = (Queue *)malloc(sizeof(Queue));

	queue->size = size;
	queue->actualSize = 0;
	queue->front = queue->size;
	queue->rear = size - 1;

	queue->array = (Item *)malloc(queue->size * sizeof(Item));

	return queue;
}

void enqueue(Queue *queue, Item item)
{
	if (isFull(queue))
		return;
	else
	{
		queue->rear = (queue->rear + 1) % queue->size; // First In...
		queue->array[queue->rear] = item;
		queue->actualSize += 1;
	}
}

Item dequeue(Queue *queue)
{
	int item = 0;

	if (isEmpty(queue))
		return INT_MIN;
	else
	{
		item = queue->array[queue->front];
		queue->front = (queue->front + 1) % queue->size; // [...] First Out
		queue->actualSize -= 1;
	}

	return item;
}

Item front(Queue *queue)
{
	if (isEmpty(queue))
		return INT_MIN;

	return queue->array[queue->front];
}

Item rear(Queue *queue)
{
	if (isEmpty(queue))
		return INT_MIN;

	return queue->array[queue->rear];
}

bool isFull(Queue *queue)
{
	return (queue->actualSize == queue->size);
}

bool isEmpty(Queue *queue)
{
	return (queue->actualSize == 0);
}

void destroyQueue(Queue *queue)
{
	if (queue != NULL)
	{
		if (queue->array != NULL)
		{
			free(queue->array);
			queue->array = NULL;
		}

		free(queue);
		queue = NULL;
	}
}

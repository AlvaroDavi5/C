#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct queue
{
	int front, rear, size;
	unsigned int actualSize;
	int *array;
};
typedef struct queue Queue; // Queue is a FIFO data structure


Queue * createQueue(unsigned int actualSize);
void freeQueue(Queue *queue);
int isFull(Queue *queue);
void enqueue(Queue *queue, int item);
int dequeue(Queue *queue);
int front(Queue *queue);
int rear(Queue *queue);
int isEmpty(Queue *queue);


int main()
{ 
	int op = 999, value = 0;
	Queue *my_queue = createQueue(50);

	do
	{
		printf("\n------------- SELECT A OPTION -------------\n");
		printf("0. Exit\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Is Empty\n");
		printf("4. First Element\n");
		printf("5. Last Element\n");

		printf("\nType a number: ");
		scanf("%d", &op);

		switch(op)
		{
			case 0:
				freeQueue(my_queue);
				exit(0);
				break;
			case 1:
				printf("\nType a value: ");
				scanf("%d",&value);
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
	} while(op != 0);
}


Queue * createQueue(unsigned int actualSize)
{
	Queue *queue = (Queue *) malloc(sizeof(Queue));

	queue->size = 0;
	queue->actualSize = actualSize;
	queue->front = queue->size; 
	queue->rear = actualSize - 1;

	queue->array = (int *) malloc(queue->actualSize * sizeof(int));

	return queue;
}

void enqueue(Queue *queue, int item)
{
	if (isFull(queue))
		return;
	else
	{
		queue->rear = (queue->rear + 1) % queue->actualSize; // First In...
		queue->array[queue->rear] = item;
		queue->size += 1;
	}
}

int dequeue(Queue *queue)
{
	int item = 0;

	if (isEmpty(queue))
		return INT_MIN;
	else
	{
		item = queue->array[queue->front];
		queue->front = (queue->front + 1) % queue->actualSize; // [...] First Out
		queue->size -= 1;
	}

	return item;
}

int front(Queue *queue)
{
	if (isEmpty(queue))
		return INT_MIN;

	return queue->array[queue->front];
}

int rear(Queue *queue)
{
	if (isEmpty(queue))
		return INT_MIN;

	return queue->array[queue->rear];
}

int isFull(Queue *queue)
{
	return (queue->size == queue->actualSize);
}

int isEmpty(Queue *queue)
{
	return (queue->size == 0);
}

void freeQueue(Queue *queue)
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

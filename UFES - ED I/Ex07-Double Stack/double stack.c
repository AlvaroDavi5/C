#include <stdlib.h>
#include "double stack.h"


struct stack
{
	int top1, top2;
	unsigned int size;
	int *array;
};


Stack * createStack(unsigned int capacity)
{
	Stack *stack = (Stack *) malloc(sizeof(Stack));

	stack->size = capacity;
	stack->top1 = -1;
	stack->top2 = capacity;

	stack->array = (int *) malloc(stack->size * sizeof(int));

	return stack;
}

void push(Stack *stack, int item, int top)
{
	if (isFull(stack))
		return;
	else if (top == 1)
		stack->array[++stack->top1] = item; // Last In...
	else
		stack->array[++stack->top2] = item;
}

int pop(Stack *stack, int top)
{
	if (isEmpty(stack))
		return -9999;
	else if (top == 1)
		return stack->array[stack->top1--]; // [...] First Out
	else
		return stack->array[stack->top2--];
}

int peek(Stack *stack, int top)
{
	if (isEmpty(stack))
		return -9999;
	else if (top == 1)
		return stack->array[stack->top1];
	else
		return stack->array[stack->top2];
}

int isFull(Stack *stack)
{
	return stack->top1 == stack->top2 -1;
}

int isEmpty(Stack *stack)
{
	return ((stack->top1 == -1) && (stack->top2 == stack->size));
}

void freeStack(Stack *stack)
{
	if (stack != NULL)
	{
		if (stack->array != NULL)
		{
			free(stack->array);
			stack->array = NULL;
		}

		free(stack);
		stack = NULL;
	}
}


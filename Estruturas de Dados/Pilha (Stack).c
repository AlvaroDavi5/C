#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define Item int

struct stack
{
	int top;
	unsigned int size;
	Item *array;
};
typedef struct stack Stack; // Stack is a LIFO data structure

Stack *createStack(unsigned int capacity);
void freeStack(Stack *stack);
void push(Stack *stack, Item item);
Item pop(Stack *stack);
Item peek(Stack *stack);
int isFull(Stack *stack);
int isEmpty(Stack *stack);

int main()
{
	int op = 999, value = 0;
	Stack *my_stack = createStack(100);

	do
	{
		printf("\n------------- SELECT A OPTION -------------\n");
		printf("0. Exit\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		printf("4. Is Empty\n");

		printf("\nType a number: ");
		scanf("%d", &op);

		switch (op)
		{
		case 0:
			freeStack(my_stack);
			exit(0);
			break;
		case 1:
			printf("\nType a value: ");
			scanf("%d", &value);
			push(my_stack, value);
			printf("\n %d pushed to stack\n", value);
			break;
		case 2:
			printf("\nPopped element: %d from stack\n", pop(my_stack));
			break;
		case 3:
			printf("\nTop element: %d\n", peek(my_stack));
			break;
		case 4:
			printf("\nIs empty: ");
			if (isEmpty(my_stack))
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

Stack *createStack(unsigned int capacity)
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));

	stack->size = capacity;
	stack->top = -1;

	stack->array = (int *)malloc(stack->size * sizeof(Item));

	return stack;
}

void push(Stack *stack, Item item)
{
	if (isFull(stack))
		return;

	stack->array[++stack->top] = item; // Last In...
}

Item pop(Stack *stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	else
	{
		return stack->array[stack->top--]; // [...] First Out
	}
}

Item peek(Stack *stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	else
	{
		return stack->array[stack->top];
	}
}

int isFull(Stack *stack)
{
	return stack->top == stack->size - 1;
}

int isEmpty(Stack *stack)
{
	return stack->top == -1;
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

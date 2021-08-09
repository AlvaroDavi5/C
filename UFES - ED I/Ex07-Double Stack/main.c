#include <stdio.h> 
#include <stdlib.h>
#include "double stack.h"


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

		switch(op)
		{
			case 0:
				freeStack(my_stack);
				exit(0);
				break;
			case 1:
				printf("\nType a value: ");
				scanf("%d",&value);
				printf("\nType 1 to push Top1 element or another value to push Top2 element: ");
				scanf("%d",&op);
				push(my_stack, value, op);
				op = 999;
				printf("\n %d pushed to stack\n", value);
				break;
			case 2:
				printf("\nType 1 to pop Top1 element or another value to pop Top2 element: ");
				scanf("%d",&value);
				printf("\nPopped element: %d from stack\n", pop(my_stack, value));
				break;
			case 3:
				printf("\nType 1 to peek Top1 element or another value to peek Top2 element: ");
				scanf("%d",&value);
				printf("\nTop element: %d\n", peek(my_stack, value));
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
	} while(op != 0);
}


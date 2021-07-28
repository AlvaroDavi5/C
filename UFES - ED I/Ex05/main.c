#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main()
{
	int op = 999, value = 0;
	LinkedList my_list = NULL;
	Node *my_node;

	my_list = initLinkedList();

	do
	{
		printf("\n------------- SELECT A OPTION -------------\n");
		printf("0. Exit\n");
		printf("1. Add New Head\n");
		printf("2. Add New Tail\n");
		printf("3. Select a Node\n");
		printf("4. Insert Next Node After Selected Node\n");
		printf("5. Insert a Value in Selected Node\n");
		printf("6. Delete Selected Node\n");
		printf("7. Display Linked List\n");

		printf("\nType a number: ");
		scanf("%d", &op);

		switch(op)
		{
			case 0:
				my_list = destroyLinkedList(my_list);
				exit(0);
				break;
			case 1:
				printf("Type a value: ");
				scanf("%d", &value);
				my_list = addNewHead(my_list, value);
				break;
			case 2:
				printf("Type a value: ");
				scanf("%d", &value);
				my_list = addNewTail(my_list, value);
				break;
			case 3:
				printf("Type a node position (starting at zero): ");
				scanf("%d", &value);
				my_node = getNode(my_list, (fptrCompare)compareData, value);
				printf("Selected!\n");
				break;
			case 4:
				my_list = insertNextNode(my_list, my_node);
				break;
			case 5:
				printf("Type a value: ");
				scanf("%d", &value);
				insertData(my_node, value);
				break;
			case 6:
				my_list = deleteNode(my_list, my_node);
				my_node = NULL;
				break;
			case 7:
				printf("\n\n");
				displayLinkedList(my_list);
				printf("\n\n");
				break;
			default:
				printf("\nInvalid option!\n");
				break;
		}
	} while (op != 0);

	return 0;
}

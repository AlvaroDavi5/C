#include<stdio.h>
#include<stdlib.h>


typedef int (* fptrCompare)(int, int);

struct node
{
	int data;
	struct node *next; // only next Node pointer...
};
typedef struct node Node;

struct list
{
	Node *head;
	Node *current; // [...] makes one-way List
	Node *tail;
};
typedef struct list LinkedList;


void initLinkedList(LinkedList *list);
void addNewHead(LinkedList *list, int value);
void addNewTail(LinkedList *list, int value);
Node * getNode(LinkedList *list, fptrCompare compareFunction, int number);
void deleteNode(LinkedList *list, Node *node);
void displayLinkedList(LinkedList *list);
int compareData(int d1, int d2);


int main()
{
	int op = 999, value = 0;
	LinkedList *my_list;
	Node *my_node;

	initLinkedList(my_list);

	do
	{
		printf("\n------------- SELECT A OPTION -------------\n");
		printf("0. Exit\n");
		printf("1. Add New Head\n");
		printf("2. Add New Tail\n");
		printf("3. Get a Node\n");
		printf("4. Delete Selected Node\n");
		printf("5. Display Linked List\n");

		printf("\nType a number: ");
		scanf("%d", &op);

		switch(op)
		{
			case 0:
				exit(0);
				break;
			case 1:
				printf("\nType a value: ");
				scanf("%d", &value);
				addNewHead(my_list, value);
				break;
			case 2:
				printf("\nType a value: ");
				scanf("%d", &value);
				addNewTail(my_list, value);
				break;
			case 3:
				printf("\nType a node number: ");
				scanf("%d", &value);
				my_node = getNode(my_list, (fptrCompare)compareData, value);
				break;
			case 4:
				deleteNode(my_list, my_node);
				break;
			case 5:
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


void initLinkedList(LinkedList *list)
{
	list->head = NULL;
	list->current = NULL;
	list->tail = NULL;
}

void addNewHead(LinkedList *list, int value)
{
	Node *node = (Node*) malloc(sizeof(Node));
	node->data = value;

	if (list->head == NULL)
	{
		list->tail = node;
		node->next = NULL;
	}
	else
	{
		node->next = list->head;
	}

	list->head = node;
}

void addNewTail(LinkedList *list, int value)
{
	Node *node = (Node*) malloc(sizeof(Node));

	node->data = value;
	node->next = NULL;

	if (list->head == NULL)
	{
		list->head = node;
	}
	else
	{
		list->tail->next = node;
	}

	list->tail = node;
}

Node * getNode(LinkedList *list, fptrCompare compareFunction, int number)
{
	Node *current = list->head;

	while (current != NULL)
	{
		if (compareFunction(current->data, number) == 0)
		{
			return current;
		}

		current = current->next;
	}

	return NULL;
}

void deleteNode(LinkedList *list, Node *node)
{
	if (node == list->head)
	{
		if (list->head->next == NULL)
		{
			list->head = list->tail;
		}
		else
		{
			list->head = list->head->next;
		}
	}
	else
	{
		Node *current = list->head;

		while (current != NULL && current->next != node)
		{
			current = current->next;
		}

		if (current != NULL)
		{
			current->next = node->next;
		}
	}

	free(node);
}

void displayLinkedList(LinkedList *list)
{
	Node *current = list->head;

	while (current != NULL)
	{
		printf("%d - ", current->data);
		current = current->next;
	}
}

int compareData(int d1, int d2)
{
	if (d1 == d2)
	{
		return 0;
	}
	else if (d2 > d1)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

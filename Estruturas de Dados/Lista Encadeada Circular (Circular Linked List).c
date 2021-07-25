#include <stdio.h>
#include <stdlib.h>


typedef int (* fptrCompare)(int, int);

struct node
{
	int index;
	int data;
	struct node *next; // only next Node pointer...
};
typedef struct node Node;

struct list
{
	int size;
	Node *head;
	Node *current; // [...] makes one-way List
	Node *tail;
};
typedef struct list LinkedList;


LinkedList * initLinkedList(LinkedList *list);
void addNewHead(LinkedList *list, int value);
void addNewTail(LinkedList *list, int value);
Node * getNode(LinkedList *list, fptrCompare compareFunction, int position);
void insertNextNode(LinkedList *list, Node *node);
void insertData(Node *node, int value);
void deleteNode(LinkedList *list, Node *node);
void destroyLinkedList(LinkedList *list);
void displayLinkedList(LinkedList *list);
int compareData(int d1, int d2);


int main()
{
	int op = 999, value = 0;
	LinkedList *my_list;
	Node *my_node;

	my_list = initLinkedList(my_list);

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
				destroyLinkedList(my_list);
				exit(0);
				break;
			case 1:
				printf("Type a value: ");
				scanf("%d", &value);
				addNewHead(my_list, value);
				break;
			case 2:
				printf("Type a value: ");
				scanf("%d", &value);
				addNewTail(my_list, value);
				break;
			case 3:
				printf("Type a node position (starting at zero): ");
				scanf("%d", &value);
				my_node = getNode(my_list, (fptrCompare)compareData, value);
				printf("Selected!\n");
				break;
			case 4:
				insertNextNode(my_list, my_node);
				break;
			case 5:
				printf("Type a value: ");
				scanf("%d", &value);
				insertData(my_node, value);
				break;
			case 6:
				deleteNode(my_list, my_node);
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


LinkedList * initLinkedList(LinkedList *list)
{
	list = (LinkedList *) malloc(sizeof(LinkedList));

	list->size = 0;
	list->head = NULL;
	list->current = NULL;
	list->tail = NULL;

	return list;
}

void addNewHead(LinkedList *list, int value)
{
	Node *node = (Node*) malloc(sizeof(Node));
	node->data = value;

	if (list->head == NULL)
	{
		list->tail = node;
		node->next = list->head;
	}
	else
	{
		node->next = list->head;
	}

	list->head = node;
	list->size += 1;

	Node *current = list->head;
	for (int i = 0; i < list->size; i++)
	{
		current->index = i;
		current = current->next;
	}
}

void addNewTail(LinkedList *list, int value)
{
	Node *node = (Node*) malloc(sizeof(Node));

	node->data = value;
	node->next = list->head;

	if (list->head == NULL)
	{
		list->head = node;
	}
	else
	{
		list->tail->next = node;
	}

	node->index = list->size;
	list->tail = node;
	list->size += 1;
}

Node * getNode(LinkedList *list, fptrCompare compareFunction, int position)
{
	Node *current = list->head;

	while (current != NULL)
	{
		if (compareFunction(current->index, position) == 0)
		{
			return current;
		}

		current = current->next;
	}

	return NULL;
}

void insertNextNode(LinkedList *list, Node *node)
{
	Node *newNode = (Node*) malloc(sizeof(Node));

	newNode->data = 0;
	newNode->next = node->next;

	if (list->head == NULL)
	{
		list->head = newNode;
	}
	else
	{
		node->next = newNode;
	}

	if (newNode->next != list->head)
	{
		newNode->index = newNode->next->index;
		Node *current = newNode->next;
		for (int i = newNode->index; i < list->size; i++)
		{
			current->index = i+1;
			current = current->next;

			if (current->index == 0)
				break;
		}
	}
	else
	{
		newNode->index = list->size;
	}
	list->size += 1;
}

void insertData(Node *node, int value)
{
	node->data = value;
}

void deleteNode(LinkedList *list, Node *node)
{
	Node *current = list->head;

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
		while (current != NULL && current->next != node)
		{
			current = current->next;
		}
		if (current != NULL && current->next == node)
		{
			current->next = node->next;
			current->next->index = node->index;
		}
	}

	free(node);
	list->size -= 1;

	Node *indexedNode = list->head;
	for (int i = 0; i < list->size; i++)
	{
		if (indexedNode != NULL)
		{
			indexedNode->index = i;
			indexedNode = indexedNode->next;
		}
	}
}

void destroyLinkedList(LinkedList *list)
{
	Node *current = list->head;
	Node *next = NULL;

	while (current->index < (list->size -1))
	{
		next = current->next;

		deleteNode(list, current);
		current = next;
	}
	deleteNode(list, current);

	free(list);
}

void displayLinkedList(LinkedList *list)
{
	Node *current = list->head;

	while (current->index < (list->size -1))
	{
		printf("%d:%d - ", current->index, current->data);
		current = current->next;
	}
	printf("%d:%d - ", current->index, current->data);
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


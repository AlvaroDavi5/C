#include <stdio.h>
#include <stdlib.h>
#include "list.h"


struct node
{
	int index;
	int data;
	struct node *prev;
	struct node *next;
};


LinkedList initLinkedList()
{
	LinkedList list = (LinkedList) malloc(sizeof(Node));

	list->prev = NULL;
	list->next = NULL;
	list->data = 0;
	list->index = 0;

	return list;
}

LinkedList addNewHead(LinkedList list, int value)
{
	Node *node = (Node *) malloc(sizeof(Node));
	node->data = value;
	node->prev = NULL;

	if (list == NULL)
	{
		list = node;
		node->next = NULL;
	}
	else
	{
		node->next = list;
		list->prev = node;
	}
	list = goToHead(list);

	Node *current = list;
	Node *previous = NULL;
	int i = 0;
	while (current != NULL)
	{
		current->index = i;
		current->prev = previous;
		previous = current;
		current = current->next;
		i++;
	}

	return list;
}

LinkedList addNewTail(LinkedList list, int value)
{
	Node *node = (Node *) malloc(sizeof(Node));

	node->data = value;
	node->next = NULL;

	if (list == NULL)
	{
		list = node;
		node->prev = NULL;
	}
	else
	{
		list = goToTail(list);
		list->next = node;
	}
	list = goToHead(list);

	Node *current = list;
	Node *previous = NULL;

	int i = 0;
	while (current != NULL)
	{
		current->index = i;
		current->prev = previous;
		previous = current;
		current = current->next;
		i++;
	}

	return list;
}

LinkedList destroyLinkedList(LinkedList list)
{
	Node *current = goToHead(list);
	Node *next = NULL;

	while (current->next != NULL)
	{
		next = current->next;

		deleteNode(list, current);
		current = next;
	}
	free(current);

	return NULL;
}

void displayLinkedList(LinkedList list)
{
	LinkedList current = goToHead(list);

	while (current != NULL)
	{
		printf("%d:%d - ", current->index, current->data);
		current = current->next;
	}
}


Node * getNode(Node *list, fptrCompare compareFunction, int position)
{
	Node *current = goToHead(list);

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

Node * insertNextNode(Node *list, Node *node)
{
	list = goToHead(list);
	Node *newNode = (Node *) malloc(sizeof(Node));

	newNode->data = 0;
	newNode->prev = node;
	newNode->next = node->next;

	if (list == NULL)
	{
		list = newNode;
		newNode->index = 0;
	}
	else
	{
		(node->next)->prev = newNode;
		node->next = newNode;
	}

	if (newNode->next != NULL)
	{
		newNode->index = (newNode->next)->index;
		Node *current = newNode->next;
		int i = newNode->index;
		while (current != NULL)
		{
			current->index = i+1;
			current = current->next;

			if (current == NULL)
				break;

			i++;
		}
	}
	else
	{
		newNode->index = goToTail(list)->index +1;
	}

	list = goToHead(list);
	return list;
}

void insertData(Node *node, int value)
{
	node->data = value;
}

Node * deleteNode(Node *list, Node *node)
{
	list = goToHead(list);
	Node *current = goToHead(list);

	if (node == list)
	{
		if (list->next == NULL)
		{
			list = goToTail(list);
		}
		else
		{
			list = list->next;
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
			(current->next)->prev = node->prev;
			current->next->index = node->index;
		}
	}

	free(node);

	Node *indexedNode = list;
	int i = 0;
	while (indexedNode != NULL)
	{
		indexedNode->index = i;
		indexedNode = indexedNode->next;

		i++;
	}

	list = goToHead(list);
	return list;
}

Node * goToHead(Node * list)
{
	Node *previous = list;

	while (previous->prev != NULL)
	{
		if (previous->prev == NULL)
			break;

		previous = previous->prev;
	}
	list = previous;

	return list;
}

Node * goToTail(Node * list)
{
	Node *next = list;

	while (next->next != NULL)
	{
		if (next->next == NULL)
			break;

		next = next->prev;
	}
	list = next;

	return list;
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


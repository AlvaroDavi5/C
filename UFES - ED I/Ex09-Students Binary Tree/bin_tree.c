#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bin_tree.h"


struct node
{
	Student *student;
	struct node *left;
	struct node *right;
};


Node * newNode(Student *stud, Node *left, Node *right)
{
	Node *node = (Node *) malloc(sizeof(Node));

	node->student = stud;
	node->left = left;
	node->right = right;

	return node;
}

int itBelongs(Node *node, char *name)
{
	if (isEmpty(node))
		return 0;
	else
		return strcmp(returnNameStudent(node->student), name) == 0 ||
		itBelongs(node->left, name) ||
		itBelongs(node->right, name);	
}

void displayInOrder(Node *node)
{
	printf("<");
	if(isEmpty(node))
	{
		printf(" ");
	}
	else
	{
		displayInOrder(node->left);
		printf("%s", returnNameStudent(node->student));
		displayInOrder(node->right);
	}
	printf(">");
}

void displayPreOrder(Node *node)
{
	printf("<");
	if(isEmpty(node))
	{
		printf(" ");
	}
	else
	{
		printf("%s", returnNameStudent(node->student));
		displayPreOrder(node->left);
		displayPreOrder(node->right);
	}
	printf(">");
}

void displayPostOrder(Node *node)
{
	printf("<");
	if(isEmpty(node))
	{
		printf(" ");
	}
	else
	{
		displayPostOrder(node->left);
		displayPostOrder(node->right);
		printf("%s", returnNameStudent(node->student));
	}
	printf(">");
}

void FreeNode(Node *node)
{
	if(isEmpty(node))
		return;
	else
	{
		FreeNode(node->left);
		FreeNode(node->right); // recursion to free all nodes

		freeStudent(node->student);
		free(node);
		node = NULL;
	}
}

int isEmpty(Node *node)
{
	if (node == NULL)
		return 1;
	else
		return 0;
}

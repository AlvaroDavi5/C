#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sbin_tree.h"


struct node
{
	Student *student;
	struct node *left;
	struct node *right;
};


Tree createTree()
{
	return NULL;
}

Node * searchTree(Node *sub_tree, int key)
{
	if (isEmpty(sub_tree))
		return NULL;
	else if (returnRegisterStudent(sub_tree->student) > key)
		return searchTree(sub_tree->left, key);
	else if (returnRegisterStudent(sub_tree->student) < key)
		return searchTree(sub_tree->right, key);
	else
		return sub_tree;
}

Node * insertTree(Node *sub_tree, Student *stud)
{
	if (isEmpty(sub_tree))
	{
		sub_tree = (Tree) malloc(sizeof(Node));
		sub_tree->student = stud;
		sub_tree->left = sub_tree->right = NULL;
	}
	else if (returnRegisterStudent(stud) < returnRegisterStudent(sub_tree->student))
		sub_tree->left = insertTree(sub_tree->left, stud);
	else
		sub_tree->right = insertTree(sub_tree->right, stud);

	return sub_tree;
}

Node * removeTree(Node *sub_tree, int value)
{
	if (isEmpty(sub_tree))
		return NULL;
	else if (returnRegisterStudent(sub_tree->student) > value)
		sub_tree->left = removeTree(sub_tree->left, value);
	else if (returnRegisterStudent(sub_tree->student) < value)
		sub_tree->right = removeTree(sub_tree->right, value);
	else
	{
		if (isEmpty(sub_tree->left) && isEmpty(sub_tree->right))
		{
			freeStudent(sub_tree->student);
			free(sub_tree);
			sub_tree = NULL;
		}
		else if (isEmpty(sub_tree->left))
		{
			Node *aux = sub_tree;
			sub_tree = sub_tree->right;
			free(aux);
		}
		else if (isEmpty(sub_tree->right))
		{
			Node *aux = sub_tree;
			sub_tree = sub_tree->left;
			free(aux);
		}
		else
		{
			Node *node = sub_tree->left;
			while (!isEmpty(sub_tree->right))
			{
				node = node->right;
				Student *stud = sub_tree->student;
				sub_tree->student = node->student;
				node->student = stud;
				sub_tree->left = removeTree(sub_tree->left, value);
			}
		}
	}
	return sub_tree;
}

int heightTree(Node *node)
{
	if (isEmpty(node))
		return -1;
	else
	{
		int lh = heightTree(node->left);
		int rh = heightTree(node->right);

		if (lh >= rh)
			return lh+1;
		else
			return rh+1;
	}
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

void freeSubTree(Node *node)
{
	if(isEmpty(node))
		return;
	else
	{
		freeSubTree(node->left);
		freeSubTree(node->right);

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

Student * returnStudent(Node *node)
{
	return node->student;
}

#ifndef BIN_TREE_H
	#define BIN_TREE_H

	#include "student.h"

	typedef struct node Node;
	typedef Node* Tree;

	Node * newNode(Student *stud, Node *left, Node *right);
	int itBelongs(Node *node, char *name);
	void displayPreOrder(Node *node);
	void displayInOrder(Node *node);
	void displayPostOrder(Node *node);
	void FreeNode(Node *node);
	int isEmpty(Node *node);

#endif

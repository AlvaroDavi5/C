#ifndef BIN_TREE_H
	#define BIN_TREE_H

	#include "student.h"

	typedef struct node Node;
	typedef Node* Tree;

	Tree createTree();
	Node * searchTree(Node *sub_tree, int key);
	Node * insertTree(Node *sub_tree, Student *stud);
	Node * removeTree(Node *sub_tree, int value);
	void displayInOrder(Node *node);
	void freeSubTree(Node *node);
	int heightTree(Node *node);
	Student * returnStudent(Node *node);
	int isEmpty(Node *node);

#endif

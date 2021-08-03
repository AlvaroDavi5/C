#ifndef _LIST_H
	#define _LIST_H

	typedef int (* fptrCompare)(int, int);
	typedef struct node Node;
	typedef Node * LinkedList;

	LinkedList initLinkedList();
	LinkedList addNewHead(LinkedList list, int value);
	LinkedList addNewTail(LinkedList list, int value);
	LinkedList destroyLinkedList(LinkedList list);
	void displayLinkedList(LinkedList list);

	Node * getNode(Node *list, fptrCompare compareFunction, int position);
	Node * insertNextNode(Node *list, Node *node);
	void insertData(Node *node, int value);
	Node * deleteNode(Node *list, Node *node);
	Node * goToHead(Node *list);
	Node * goToTail(Node *list);

	int compareData(int d1, int d2);

#endif


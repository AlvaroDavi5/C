#ifndef _TREE_H

#define _TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "./utils.h"

typedef struct node Node;
typedef Node *Tree;

Node *newNode(int key, Node *left, Node *right);
Node *createUnbalancedTree(int keyAmount);
void appendToNode(Node *node, Node *nodeToAppend);
void setLeftNode(Node *node, Node *left);
void setRightNode(Node *node, Node *right);
int itBelongs(Node *node, int key);
int leafsCount(Node *node);
int occurrencesCount(Node *node, int key);
int height(Node *node);
void displayInOrder(Node *node);
void display2D(Node *node, int space);
void FreeNode(Node *node);
int isEmpty(Node *node);

#endif

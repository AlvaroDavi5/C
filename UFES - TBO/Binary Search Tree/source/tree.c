#include "../include/tree.h"

struct node
{
	int key;
	struct node *left;
	struct node *right;
};

Node *newNode(int key, Node *left, Node *right)
{
	Node *node = (Node *)malloc(sizeof(Node));

	node->key = key;
	node->left = left;
	node->right = right;

	return node;
}

Node *createUnbalancedTree(int keyAmount)
{
	Tree treeRoot = newNode(getRandomValue(), NULL, NULL);

	for (int i = 0; i < keyAmount; i++)
	{
		int newKey = getRandomValue();
		Node *nodeToAdd = newNode(newKey, NULL, NULL);

		if (occurrencesCount(treeRoot, newKey) == 0)
		{
			appendToNode(treeRoot, nodeToAdd);
		}
	}

	return treeRoot;
}

void appendToNode(Node *node, Node *nodeToAppend)
{
	if (nodeToAppend->key < node->key)
	{
		if (isEmpty(node->left))
			setLeftNode(node, nodeToAppend);
		else
			appendToNode(node->left, nodeToAppend);
	}
	if (nodeToAppend->key > node->key)
	{
		if (isEmpty(node->right))
			setRightNode(node, nodeToAppend);
		else
			appendToNode(node->right, nodeToAppend);
	}
}

void setLeftNode(Node *node, Node *left)
{
	node->left = left;
}

void setRightNode(Node *node, Node *right)
{
	node->right = right;
}

int itBelongs(Node *node, int key)
{
	if (isEmpty(node))
		return 0;
	else
		return node->key == key ||
					 itBelongs(node->left, key) ||
					 itBelongs(node->right, key);
}

int leafsCount(Node *node)
{
	if (isEmpty(node->left) && isEmpty(node->right))
		return 1;

	if (!isEmpty(node->left) && isEmpty(node->right))
		return leafsCount(node->left);

	if (isEmpty(node->left) && !isEmpty(node->right))
		return leafsCount(node->right);

	else
		return (leafsCount(node->left) + leafsCount(node->right));
}

int occurrencesCount(Node *node, int key)
{
	if (isEmpty(node))
		return 0;

	if (node->key == key)
		return (1 + occurrencesCount(node->left, key) + occurrencesCount(node->right, key));

	return (occurrencesCount(node->left, key) + occurrencesCount(node->right, key));
}

int height(Node *node)
{
	if (isEmpty(node))
		return -1;
	else
	{
		int lh = height(node->left);
		int rh = height(node->right);

		if (lh >= rh)
			return lh + 1;
		else
			return rh + 1;
	}
}

void displayInOrder(Node *node)
{
	printf("<");
	if (isEmpty(node))
	{
		printf(" ");
	}
	else
	{
		displayInOrder(node->left);
		printf("%d", node->key);
		displayInOrder(node->right);
	}
	printf(">");
}

void display2D(Node *node, int space)
{
	if (node == NULL)
		return;

	space += 2;

	display2D(node->right, space);

	printf("\n");
	for (int i = 2; i < space; i++)
		printf(" ");
	printf("%d\n", node->key);

	display2D(node->left, space);
}

void FreeNode(Node *node)
{
	if (isEmpty(node))
		return;
	else
	{
		FreeNode(node->left);
		FreeNode(node->right);

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char *name;
	struct node *left;
	struct node *right;
};
typedef struct node Node;
typedef Node *Tree;

Node *newNode(char *name, Node *left, Node *right);
int isEmpty(Node *node);
int itBelongs(Node *node, char *name);
int leafsCount(Node *node);
int occurrencesCount(Node *node, char *name);
int height(Node *node);
void displayPreOrder(Node *node);	 // starts at the root and goes first to the left branch and then to the right branch
void displayInOrder(Node *node);	 // starts on the left branch, goes through the root and goes to the right branch
void displayPostOrder(Node *node); // starts on the left branch and goes first to the right branch and then to the root
void destroyNode(Node *node);

int main()
{
	char *name = "e";
	Tree binTree = NULL;

	binTree = newNode(
			"root",
			newNode(
					"a",
					newNode("c", NULL, NULL),
					NULL),
			newNode(
					"b",
					newNode("d", NULL, NULL),
					newNode(
							"e",
							NULL,
							newNode("f", NULL, NULL))));

	printf("\nElements in InOrder: ");
	displayInOrder(binTree);
	printf("\nElements in PreOrder: ");
	displayPreOrder(binTree);
	printf("\nElements in PostOrder: ");
	displayPostOrder(binTree);
	printf("\n\n");
	if (itBelongs(binTree, name))
		printf("The element '%s' exists on tree and have %d occurrences.", name, occurrencesCount(binTree, name));
	printf("\n");
	printf("The tree height is: %d and has %d nodes.\n", height(binTree), leafsCount(binTree));

	destroyNode(binTree);

	return 0;
}

Node *newNode(char *name, Node *left, Node *right)
{
	Node *node = (Node *)malloc(sizeof(Node));

	node->name = strdup(name);
	node->left = left;
	node->right = right;

	return node;
}

int isEmpty(Node *node)
{
	if (node == NULL)
		return 1;
	else
		return 0;
}

int itBelongs(Node *node, char *name)
{
	if (isEmpty(node))
		return 0;
	else
		return strcmp(node->name, name) == 0 ||
					 itBelongs(node->left, name) ||
					 itBelongs(node->right, name);
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

int occurrencesCount(Node *node, char *name)
{
	if (isEmpty(node))
		return 0; // ignore first node (its more praticle compare first node outside the function)

	if (strcmp(node->name, name) == 0)
		return (1 + occurrencesCount(node->left, name) + occurrencesCount(node->right, name));

	return (occurrencesCount(node->left, name) + occurrencesCount(node->right, name)); // recursive iteration
}

int height(Node *node)
{
	if (isEmpty(node))
		return -1; // empty tree height (just root node)
	else
	{
		int lh = height(node->left);
		int rh = height(node->right);

		if (lh >= rh)
			return lh + 1; // compense '-1' from empty nodes (last/leaf nodes)
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
		printf("%s", node->name);
		displayInOrder(node->right);
	}
	printf(">");
}

void displayPreOrder(Node *node)
{
	printf("<");
	if (isEmpty(node))
	{
		printf(" ");
	}
	else
	{
		printf("%s", node->name);
		displayPreOrder(node->left);
		displayPreOrder(node->right);
	}
	printf(">");
}

void displayPostOrder(Node *node)
{
	printf("<");
	if (isEmpty(node))
	{
		printf(" ");
	}
	else
	{
		displayPostOrder(node->left);
		displayPostOrder(node->right);
		printf("%s", node->name);
	}
	printf(">");
}

void destroyNode(Node *node)
{
	if (isEmpty(node))
		return;
	else
	{
		destroyNode(node->left);
		destroyNode(node->right); // recursion to free all nodes

		free(node->name);
		free(node);
		node = NULL;
	}
}

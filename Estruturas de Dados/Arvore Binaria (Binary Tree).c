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
typedef Node* Tree;


Node * newNode(char *name, Node *left, Node *right);
int itBelongs(Node *node, char *name);
void displayPreOrder(Node *node); // starts at the root and goes first to the left branch and then to the right branch
void displayInOrder(Node *node); // starts on the left branch, goes through the root and goes to the right branch
void displayPostOrder(Node *node); // starts on the left branch and goes first to the right branch and then to the root
void FreeNode(Node *node);
int isEmpty(Node *node);


int main ()
{
	char *charac = "e";
	Tree binTree = NULL;

	binTree = newNode(
		"root",
		newNode(
			"a",
			newNode("c", NULL, NULL),
			NULL
		),
		newNode(
			"b",
			newNode("d", NULL, NULL),
			newNode(
				"e",
				NULL,
				newNode("f", NULL, NULL)
			)
		)
	);

	printf("\nElements in displayInOrder: ");
	displayInOrder(binTree);
	printf("\nElements in displayPreOrder: ");
	displayPreOrder(binTree);
	printf("\nElements in displayPostOrder: ");
	displayPostOrder(binTree);
	printf("\n\n");
	if (itBelongs(binTree, charac))
		printf("The element '%s' exists on tree", charac);
	printf("\n");

	FreeNode(binTree);

	return 0;
}

Node * newNode(char *name, Node *left, Node *right)
{
	Node *node = (Node *) malloc(sizeof(Node));

	node->name = strdup(name);
	node->left = left;
	node->right = right;

	return node;
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
		printf("%s", node->name);
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
		printf("%s", node->name);
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
		printf("%s", node->name);
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

		free(node->name);
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

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


struct node
{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node Node;


Node * insert(Node *node, int value);
void inOrder(Node *node);
void preOrder(Node *node);
void postOrder(Node *node);
void FreeNode(Node *node);


int main ()
{
	srand(time(NULL));

	int ins_num = 5;
	Node *root = NULL;

	printf("Type insertions number: ");
	scanf("%d", &ins_num);

	for(int count = 0; count < ins_num; count++)
		root = insert(root, (rand() % 99));

	printf("\nElements in inorder: ");
	inOrder(root);
	printf("\nElements in preorder: ");
	preOrder(root);
	printf("\nElements in postorder: ");
	postOrder(root);

	FreeNode(root);

	return 0;
}

Node * insert(Node *node, int value)
{
	Node *tmp;
	tmp = (Node *) malloc(sizeof(Node));

	if(node == NULL)
	{
		tmp->data = value;
		tmp->left = NULL;
		tmp->right = NULL;

		return tmp;
	}
	else
	{
		if(value < (tmp->data))
		{
			node->left = insert(node->left, value);
		}
		else
		{
			node->right = insert(node->right, value);
		}
	}

	return node;
}

void inOrder(Node *node)
{
	if(node == NULL)
	{
		return;
	}
	else
	{
		inOrder(node->left);
		printf(" %d ", node->data);
		inOrder(node->right);
	}

}

void preOrder(Node *node)
{
	if(node != NULL)
	{
		printf(" %d ", node->data);
		preOrder(node->left);
		preOrder(node->right);
	}
}

void postOrder(Node *node)
{
	if(node != NULL)
	{
		postOrder(node->left);
		postOrder(node->right);
		printf(" %d ", node->data);
	}
}

void FreeNode(Node *node)
{
	if(node == NULL)
		return;
	else
	{
		FreeNode(node->left);
		FreeNode(node->right); // recursion to free all nodes
		node->data = 0;

		free(node);
		node = NULL;
	}
}

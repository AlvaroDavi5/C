#include <stdio.h>
#include <stdlib.h>
#include "../include/tree.h"

int main()
{
	srand(time(NULL));

	Tree binSearchTree = createUnbalancedTree(20);

	printf("\nElements in InOrder: ");
	display2D(binSearchTree, 0);
	printf("\n\n");
	printf("The tree height is: %d and has %d leaf nodes.\n", height(binSearchTree), leafsCount(binSearchTree));

	FreeNode(binSearchTree);

	return 0;
}

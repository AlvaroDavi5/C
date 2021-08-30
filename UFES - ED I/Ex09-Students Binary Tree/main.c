#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "bin_tree.h"


int main ()
{
	char *name = "e";
	Tree binTree = NULL;

	binTree = newNode(
		createStudent(001, "Aluno Exemplar", 10.0),
		newNode(
			createStudent(002, "Boa Aluna", 9.5),
			newNode(
				createStudent(004, "O que Passa Colando", 7.0),
				NULL,
				NULL
			),
			NULL
		),
		newNode(
			createStudent(03, "O Conversadeiro", 6.7),
			newNode(
				createStudent(005, "A que Vem pra Dormir", 5.0),
				NULL,
				NULL
			),
			newNode(
				createStudent(6, "Cara do Fundão", 3.2),
				NULL,
				newNode(
					createStudent(007, "O que o Professor Nunca Viu", 0.0),
					NULL,
					NULL
				)
			)
		)
	);

	printf("\nElements in InOrder:\n");
	displayInOrder(binTree);
	printf("\nElements in PreOrder:\n");
	displayPreOrder(binTree);
	printf("\nElements in PostOrder:\n");
	displayPostOrder(binTree);
	printf("\n\n");
	if (itBelongs(binTree, name))
		printf("The element '%s' exists on tree and have %d occurrences.", name, occurrencesCount(binTree, name));
	printf("\n");
	printf("The tree height is: %d and has %d nodes.\n", height(binTree), leafsCount(binTree));

	FreeNode(binTree);

	return 0;
}

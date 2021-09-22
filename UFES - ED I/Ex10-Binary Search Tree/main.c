#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "sbin_tree.h"


int main ()
{
	Tree binTree = createTree();

	binTree = insertTree(binTree, createStudent(001, "Aluno Exemplar", 10.0));
	binTree = insertTree(binTree, createStudent(002, "Boa Aluna", 9.5));
	binTree = insertTree(binTree, createStudent(004, "O que Passa Colando", 7.0));
	binTree = insertTree(binTree, createStudent(03, "O Conversadeiro", 6.7));
	binTree = insertTree(binTree, createStudent(005, "A que Vem pra Dormir", 5.0));
	binTree = insertTree(binTree, createStudent(6, "Cara do Fundão", 3.2));
	binTree = insertTree(binTree, createStudent(007, "O que o Professor Nunca Viu", 0.0));


	displayInOrder(binTree);
	printf("\n\n");
	Student *stud = returnStudent(searchTree(binTree, 7));
	printf("Achado aluno de Matrícula %d: %s\n", returnRegisterStudent(stud), returnNameStudent(stud));
	printf("Desmatriculando Aluno...\n\n");
	removeTree(binTree, 7);
	displayInOrder(binTree);
	printf("\n");

	freeSubTree(binTree);

	return 0;
}

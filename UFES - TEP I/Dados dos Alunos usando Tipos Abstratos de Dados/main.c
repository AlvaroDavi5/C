#include <stdio.h>
#include <stdlib.h>
#include "myfuncs.h"


int main()
{
	int numAlunos = 0;

	printf("Digite o número de alunos: ");
	scanf("%i", &numAlunos);

	strc_aluno * vetorAlunos[numAlunos];


	char nome[20] = "";
	int matricula = 0;
	float n1 = 0, n2 = 0, n3 = 0;

	for (int i = 0; i < numAlunos; i++)
	{
		scanf("%s", nome);
		scanf("%d", &matricula);
		scanf("%f %f %f", &n1, &n2, &n3);

		*(vetorAlunos + i) = lerAlunos(nome, matricula, n1, n2, n3);
	}


	ordenaMatricula(vetorAlunos, numAlunos);

	declaraAprovados(vetorAlunos, numAlunos);

	return 0;
}

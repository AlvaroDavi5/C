#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myfuncs.h"


/*
os endereços dos parametros da funcao sao maiores que os das variaveis locais
pois sao carregados depois, na base da pilha de execucao
enquanto as variaveis locais sao carregadas quando a funcao e chamada
*/
strc_aluno * lerAlunos(char *nome, int matricula, float n1, float n2, float n3)
{
	strc_aluno * aluno = NULL; 
	aluno = (strc_aluno *) malloc(sizeof(strc_aluno));

	aluno->nome = strdup(nome);
	aluno->matricula = matricula;
	aluno->n1 = n1;
	aluno->n2 = n2;
	aluno->n3 = n3;

	return aluno; // funcao retorna ponteiro
}


int verificaMedia(strc_aluno *a)
{
	float soma = a->n1 + a->n2 + a->n3;
	float media = (soma / 3);

	return media >= 7 ? 1 : 0;
}


void ordenaMatricula(strc_aluno ** alunos, int qtd)
{
	strc_aluno * aux = NULL;

	for (int i = 0; i < qtd; i++)
	{
		for (int j = 0; j < qtd; ++j)
		{
			if ((*(alunos + i))->matricula < (*(alunos + j))->matricula)
			{
				aux = *(alunos + i);
				*(alunos + i) = *(alunos + j);
				*(alunos + j) = aux;
			}
		}
	}
}


void declaraAprovados(strc_aluno ** alunos, int qtd)
{
	printf("Alunos Aprovados:\n");
	for (int i = 0; i < qtd; ++i)
	{
		if (verificaMedia(*(alunos + i)))
		{
			printf("%s\n", (*(alunos + i))->nome);
		}
		liberaMemoria(*(alunos + i));
	}
}


void liberaMemoria(strc_aluno *a)
{
	if (a != NULL)
	{
		if (a->nome != NULL)
			free(a->nome);

		free(a);
		a = NULL;
	}
}

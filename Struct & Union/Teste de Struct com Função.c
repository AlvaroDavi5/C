#include <stdio.h>
#include <math.h>

typedef struct /* tipo complexo */
{
	int idade;
	float nota; // tipos primitivos compondo o struct
	int matricula;
} tEstudante; // atribui o nome 'tEstudante' para o tipo complexo struct (em escopo global) ao mesmo tempo em que serve de identificador ao struct referido

void imprime(tEstudante aluno);

int main()
{
	tEstudante aluno = {18, 9.5, 20201010};; // atribuir valores às variáveis da variável aluno, definida no struct

	imprime(aluno);

	return 0;
}

void imprime(tEstudante aluno) // variáável 'aluno' do tipo 'tEstudante' passada como parametro
{
	printf("%i %.2f %i", aluno.idade, aluno.nota, aluno.matricula);
	return;
}
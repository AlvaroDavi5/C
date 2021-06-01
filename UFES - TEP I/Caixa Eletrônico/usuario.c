#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"


struct usr
{
	char *nome;
	int cpf;
	int numConta;
};


Usuario * criarUsuario(char *nome, int cpf, int numConta)
{
	Usuario *user = NULL;

	user = (Usuario *) malloc(sizeof(Usuario));
	//user->nome = (char *) malloc(strlen(nome) * sizeof(char));

	user->nome = strdup(nome);
	user->cpf = cpf;
	user->numConta = numConta;

	return user;
}

char * obterNomeUsuario(Usuario *user)
{
	return user->nome;
}

int obterCpfUsuario(Usuario *user)
{
	return user->cpf;
}

int obterContaUsuario(Usuario *user)
{
	return user->numConta;
}

void deletarUsuario(Usuario *user)
{
	if (user != NULL)
	{
		if (user->nome != NULL)
		{
			free(user->nome);
			user->nome = NULL;
		}

		free(user);
		user = NULL;
	}
}

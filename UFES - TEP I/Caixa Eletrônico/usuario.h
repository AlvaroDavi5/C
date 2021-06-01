#ifndef _USUARIO_H_

	#define _USUARIO_H_

	typedef struct usr Usuario;

	Usuario * criarUsuario(char *nome, int cpf, int numConta);
	char * obterNomeUsuario(Usuario *user);
	int obterCpfUsuario(Usuario *user);
	int obterContaUsuario(Usuario *user);
	void deletarUsuario(Usuario *user);

#endif

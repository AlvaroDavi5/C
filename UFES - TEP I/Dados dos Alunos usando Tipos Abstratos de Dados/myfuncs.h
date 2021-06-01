#ifndef _MY_FUNCS_

	#define _MY_FUNCS_

	struct struct_aluno
	{
		char *nome;
		int matricula;
		float n1;
		float n2;
		float n3;
	};
	typedef struct struct_aluno strc_aluno;

	strc_aluno * lerAlunos(char *nome, int matricula, float n1, float n2, float n3);
	int verificaMedia(strc_aluno *a);
	void ordenaMatricula(strc_aluno ** alunos, int qtd);
	void declaraAprovados(strc_aluno ** alunos, int qtd);
	void liberaMemoria(strc_aluno *a);

#endif

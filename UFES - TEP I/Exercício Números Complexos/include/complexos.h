#ifndef _COMPLEXOS_ // se o header (cabecalho) nao esta definido,

	#define _COMPLEXOS_ // definir header. com apenas um '_' para a variavel de qualquer biblioteca, pois dois '_' sao para variaveis de bibliotecas ja incluidas na linguagem/sistema/compilador

	// definicoes de tipos e constantes
	#define FALSE 0
	#define TRUE 1
	typedef struct D_Complexo_s* D_Complexo_pt;

	// prototipo de funcao
	D_Complexo_pt atribuirComplexo(double real, double imaginario);
	void exibirComplexo(D_Complexo_pt pt_valor);
	D_Complexo_pt somarComplexo(D_Complexo_pt pt_val1, D_Complexo_pt pt_val2);
	float raiz(float numero);

#endif

#ifndef PRODFUNC_H // se PRODFUNC_H não está definida

	#define PRODFUNC_H // defina PRODFUNC_H (esse header)

	// definição do tipo complexo
	typedef struct
	{
		int COD;
		float PRE;
		int QTD;
	} tProduto;

	// prototipos de todas as funções
	tProduto LeProduto();
	int EhProduto1MaiorQ2(tProduto p1, tProduto p2);
	int EhProduto1MenorQ2(tProduto p1, tProduto p2);
	int TemProdutoEmEstoque(tProduto p);
	void ImprimeProduto(tProduto p);

#endif

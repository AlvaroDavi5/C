#include <stdio.h> // por estar no diretório do compilador, aqui a inclusão do arquivo biblioteca é feita com < >
#include <stdlib.h>
#include "prodfunc.h" // por estar no mesmo diretório, aqui a inclusão do arquivo cabeçalho é feita com " "

// todas as funções
tProduto LeProduto()
{
	int codigo, quantidade;
	float preco;
	tProduto prod;

	scanf("%d;%f;%d", &codigo, &preco, &quantidade);

	prod.COD = codigo;
	prod.PRE = preco;
	prod.QTD = quantidade;

	return prod;
}

int EhProduto1MaiorQ2(tProduto p1, tProduto p2)
{
	if (p1.PRE >= p2.PRE)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int EhProduto1MenorQ2(tProduto p1, tProduto p2)
{
	if (p1.PRE <= p2.PRE)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int TemProdutoEmEstoque(tProduto p)
{
	if (p.QTD != 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void ImprimeProduto(tProduto p)
{
	printf("COD ");
	printf("%d, ", p.COD);
	printf("PRE ");
	printf("%.2f, ", p.PRE);
	printf("QTD ");
	printf("%d\n", p.QTD);

	return;
}

#include <stdio.h>
#include <stdlib.h>
#include "listaMat.h"


int main()
{
	// matrizes criadas
	Matriz *mat3x3, *mat3x2, *mat2x4, *mat5x2;
	mat3x3 = inicializaMatriz(3, 3);
	mat3x2 = inicializaMatriz(3, 2);
	mat2x4 = inicializaMatriz(2, 4);
	mat5x2 = inicializaMatriz(5, 2);

	// matrizes preenchidas
	int i, j;
	for (i = 0; i < recuperaNLinhas(mat3x3); i++)
	{
		for (j = 0; j < recuperaNColunas(mat3x3); j++)
		{
			modificaElemento(mat3x3, i, j, i+j);
		}
	}
	for (i = 0; i < recuperaNLinhas(mat3x2); i++)
	{
		for (j = 0; j < recuperaNColunas(mat3x2); j++)
		{
			modificaElemento(mat3x2, i, j, i+j);
		}
	}
	for (i = 0; i < recuperaNLinhas(mat2x4); i++)
	{
		for (j = 0; j < recuperaNColunas(mat2x4); j++)
		{
			modificaElemento(mat2x4, i, j, i+j);
		}
	}
	for (i = 0; i < recuperaNLinhas(mat5x2); i++)
	{
		for (j = 0; j < recuperaNColunas(mat5x2); j++)
		{
			modificaElemento(mat5x2, i, j, i+j);
		}
	}
	Matriz *tpMat3x3 = transposta(mat3x3), *tpMat3x2 = transposta(mat3x2), *tpMat2x4 = transposta(mat2x4);

	// lista iniciada e populada
	printf(" ------------ Lista 1 ------------ ");
	ListaMatriz *lista;
	lista = iniciarListaMatriz(lista);

	// definicao de elemento inicial e final da lista
	adcAoTopo(lista, mat3x3);
	adcAoFinal(lista, mat2x4);
	// redefinicao dos elementos acima
	adcAoFinal(lista, transposta(mat5x2));
	adcAoTopo(lista, mat5x2);

	// criacao de um proximo elemento com base no indice de outro
	inserirProxElemento(lista, obterElemento(lista, compararData, 2));
	inserirMatriz(obterElemento(lista, compararData, 3), mat3x2);
	deletarElemento(lista, obterElemento(lista, compararData, 2)); // elemento escolhido deletado

	// lista exibida e destruida
	mostrarListaMatriz(lista);
	destruirListaMatriz(lista);


	// segundo teste, apenas com transpostas
	printf(" ------------ Lista 2 ------------ ");
	ListaMatriz *outraLista;
	outraLista = iniciarListaMatriz(outraLista);

	adcAoTopo(outraLista, transposta(tpMat2x4));
	adcAoFinal(outraLista, transposta(tpMat3x2));
	adcAoTopo(outraLista, transposta(tpMat3x3));
	adcAoFinal(outraLista, transposta(tpMat3x2));

	deletarElemento(outraLista, obterElemento(outraLista, compararData, 2));
	deletarElemento(outraLista, obterElemento(outraLista, compararData, 0));

	adcAoTopo(outraLista, tpMat3x3);
	adcAoFinal(outraLista, tpMat2x4);
	adcAoTopo(outraLista, tpMat3x2);

	mostrarListaMatriz(outraLista);
	destruirListaMatriz(outraLista);

	return 0;
}


/*
 *********************************
 * Programa testador do TAD Matriz
 *********************************
 */
#include <stdio.h>
#include "matriz.h"


//definindo constantes para o número de linhas e colunas da matriz
#define M_LINHAS 4
#define N_COLUNAS 3


int main()
{
	//chamando a funcao do TAD Matriz que inicializa a matriz
	Matriz *mat = inicializaMatriz(M_LINHAS, N_COLUNAS);

	//preenchendo a matriz com valores para teste
	int i, j;
	for (i=0;i < M_LINHAS;i++)
		for (j=0;j < N_COLUNAS; j++)
			modificaElemento(mat, i, j,i+j); //chamando a funcao do TAD matriz para modificar um dado elemento da matriz

	//chamando a funcao do TAD matriz para imprimir os elementos da matriz
	imprimeMatriz(mat);


	//chamando a função do TAD para gerar a matriz transposta
	Matriz *trp = transposta(mat);
	printf ("A matriz transposta eh: \n");
	imprimeMatriz(trp);


	//chamando a função do TAD para gerar a matriz multiplicacao
	Matriz* mlt = multiplicacao(mat,trp);
	printf ("A matriz multiplicacao eh: \n");
	imprimeMatriz(mlt);


	// destruindo TADs matrizes
	destroiMatriz(mat);
	destroiMatriz(trp);
	destroiMatriz(mlt);
}


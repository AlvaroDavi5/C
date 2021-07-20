#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"


struct matriz
{
	int linhas;
	int colunas;
	int **matriz;
};


Matriz* inicializaMatriz (int nlinhas, int ncolunas)
{
	if (nlinhas > 0 && ncolunas > 0)
	{
		Matriz *mat = (Matriz *) malloc(sizeof(Matriz));
		mat->linhas = nlinhas;
		mat->colunas = ncolunas;
        	mat->matriz = (int **) malloc(nlinhas * sizeof(int *));

	        for (int i = 0; i < nlinhas; i++)
        	{
                	(mat->matriz)[i] = (int *)malloc(ncolunas * sizeof(int));
	        }
 
		return mat;
	}
	else
		return NULL;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem)
{
	if (mat != NULL)
		if ((linha < mat->linhas && linha >= 0) && (coluna < mat->colunas && coluna >= 0))
			(mat->matriz)[linha][coluna] = elem;
}

int recuperaElemento(Matriz* mat, int linha, int coluna)
{
	if (mat != NULL)
	{
		if ((linha < mat->linhas && linha >= 0) && (coluna < mat->colunas && coluna >= 0))
			return (mat->matriz)[linha][coluna]; 
		else
			return 0;
	}
	else
		return 0;
}

int recuperaNColunas (Matriz* mat)
{
	if (mat != NULL)
		return mat->colunas;
}

int recuperaNLinhas (Matriz* mat)
{
	if (mat != NULL)
		return mat->linhas;
}

Matriz* transposta (Matriz* mat)
{
	Matriz *transposta = inicializaMatriz(mat->colunas, mat->linhas);

	for(int i = 0; i < mat->linhas; i++)
		for(int j = 0; j < mat->colunas; j++)
			(transposta->matriz)[j][i] = (mat->matriz)[i][j];

	return transposta;
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2)
{
	int i = 0, j = 0, k = 0, somatorio = 0;

	if(mat1->colunas == mat2->linhas)
	{
		Matriz *mult = inicializaMatriz(mat1->linhas, mat2->colunas);

		for(i = 0; i < mat1->linhas; i++)
		{
			for(j = 0; j < mat2->colunas; j++)
			{
				somatorio = 0;

				for(k = 0; k < mat1->colunas; k++)
					somatorio += (mat1->matriz)[i][k] * (mat2->matriz)[k][j];

				(mult->matriz)[i][j] = somatorio;
			}
		}

		return mult;
	}
	else
		return NULL;
}

void imprimeMatriz(Matriz* mat)
{
	for(int i = 0; i < mat->linhas; i++)
	{
		for(int j = 0; j < mat->colunas; j++)
		{
			printf("%d ", (mat->matriz)[i][j]);
		}
		printf("\n");
	}
}

void destroiMatriz(Matriz* mat)
{
	if (mat != NULL)
	{
		if (mat->matriz != NULL)
		{
			for (int i = 0; i < mat->linhas; i++)
			{
				free(mat->matriz[i]);
			}
			free(mat->matriz);
		}
		free(mat);
		mat = NULL;
	}
}


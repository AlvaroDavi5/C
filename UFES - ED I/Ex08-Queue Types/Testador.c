#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"


#define TAM 10


int main()
{
	FilaVetor *filaVet = criarFilaVetor(TAM);
	FilaLista *filaList = criarFilaLista(TAM);


	for (int i = 0; i < TAM; i++)
	{
		enfileirarFilaVetor(filaVet, i);
	}

	for (int j = 0; j < TAM; j++)
	{
		enfileirarFilaLista(filaList, j);
	}


	printf("Antes de desenfileirar: \n");
	printf("Fila Vetor: ");
	imprimeFilaVetor(filaVet);
	printf("Fila Lista: ");
	imprimeFilaLista(filaList);

	desenfileirarFilaVetor(filaVet);
	desenfileirarFilaVetor(filaVet);
	desenfileirarFilaLista(filaList);
	desenfileirarFilaLista(filaList);

	printf("Depois de desenfileirar: \n");
	printf("Fila Vetor: ");
	imprimeFilaVetor(filaVet);
	printf("Fila Lista: ");
	imprimeFilaLista(filaList);


	liberarFilaVetor(filaVet);
	liberarFilaLista(filaList);

	return 0;
}


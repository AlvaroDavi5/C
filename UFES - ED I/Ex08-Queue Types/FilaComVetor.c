#include "Fila.h"


struct fila_vet
{
	int inicioFila, finalFila, tamanhoFila;
	int tamanhoAtual; // filas são estruturas de dados FIFO, fist-in first-out
	int *vetor;
};


FilaVetor * criarFilaVetor(int tamanhoAtual)
{
	FilaVetor *fila = (FilaVetor *) malloc(sizeof(FilaVetor));

	fila->tamanhoFila = 0;
	fila->tamanhoAtual = tamanhoAtual;
	fila->inicioFila = fila->tamanhoFila; 
	fila->finalFila = tamanhoAtual - 1;

	fila->vetor = (int *) malloc(fila->tamanhoAtual * sizeof(int));

	return fila;
}

void enfileirarFilaVetor(FilaVetor *fila, int item)
{
	if (estaCheiaFilaVetor(fila))
		return;
	else
	{
		fila->finalFila = (fila->finalFila + 1) % fila->tamanhoAtual; // First In...
		fila->vetor[fila->finalFila] = item;
		fila->tamanhoFila += 1;
	}
}

int desenfileirarFilaVetor(FilaVetor *fila)
{
	int item = 0;

	if (estaVaziaFilaVetor(fila))
		return INT_MIN;
	else
	{
		item = fila->vetor[fila->inicioFila];
		fila->inicioFila = (fila->inicioFila + 1) % fila->tamanhoAtual; // [...] First Out
		fila->tamanhoFila -= 1;
	}

	return item;
}

int inicioFilaVetor(FilaVetor *fila)
{
	if (estaVaziaFilaVetor(fila))
		return INT_MIN;

	return fila->vetor[fila->inicioFila];
}

int finalFila(FilaVetor *fila)
{
	if (estaVaziaFilaVetor(fila))
		return INT_MIN;

	return fila->vetor[fila->finalFila];
}

int estaCheiaFilaVetor(FilaVetor *fila)
{
	return (fila->tamanhoFila == fila->tamanhoAtual);
}

int estaVaziaFilaVetor(FilaVetor *fila)
{
	return (fila->tamanhoFila == 0);
}

void liberarFilaVetor(FilaVetor *fila)
{
	if (fila != NULL)
	{
		if (fila->vetor != NULL)
		{
			free(fila->vetor);
			fila->vetor = NULL;
		}

		free(fila);
		fila = NULL;
	}
}

void imprimeFilaVetor(FilaVetor *fila)
{
	for (int i = 0; i < fila->tamanhoFila; i++)
	{
		printf("%d, ", fila->vetor[i]);
	}
	printf("\n");
}


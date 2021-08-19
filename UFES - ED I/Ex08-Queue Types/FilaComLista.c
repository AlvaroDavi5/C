#include "Fila.h"


struct celula
{
	int valor;
	Celula *prox;
};

struct fila_list
{
	Celula *inicioFila;
	Celula *finalFila;
};


Celula * criarCelula(int valor)
{
  Celula *cell = (Celula*) malloc(sizeof(Celula));

  cell->valor = valor;

  return cell;
}

FilaLista * criarFilaLista(int tamanhoAtual)
{
	FilaLista *fila = (FilaLista *) malloc(sizeof(FilaLista));

	fila->inicioFila = NULL; 
	fila->finalFila = NULL;

	return fila;
}

void enfileirarFilaLista(FilaLista *fila, int item)
{
  Celula *cell = criarCelula(item);

  if (estaVaziaFilaLista(fila))
	{
		cell->prox = NULL;
		fila->inicioFila = cell;
		fila->finalFila = cell;
		return;
	}

	cell->prox = fila->inicioFila;
	fila->inicioFila = cell;
}

void desenfileirarFilaLista(FilaLista *fila)
{
	if (estaVaziaFilaLista(fila))
		return;

	Celula *anterior = fila->inicioFila;
	Celula *atual = anterior->prox->prox;

	while (atual != NULL)
	{
		anterior = anterior->prox;
		atual = atual->prox;
	}

	anterior->prox = NULL;
	free(fila->finalFila);
	fila->finalFila = anterior;
}

int estaVaziaFilaLista(FilaLista *fila)
{
	return (fila->inicioFila == NULL) ? TRUE : FALSE;
}

void liberarFilaLista(FilaLista *fila)
{
  Celula *cell = fila->inicioFila;

  while (cell != NULL) {
    Celula *aux = cell;
    cell = cell->prox;
    free(aux);
  }

  free(fila);
}

void imprimeFilaLista(FilaLista *fila)
{
  Celula *cell = fila->inicioFila;

  while (cell != NULL)
	{
		printf("%d, ", cell->valor);
		cell = cell->prox;
	}

	printf("\n");
}


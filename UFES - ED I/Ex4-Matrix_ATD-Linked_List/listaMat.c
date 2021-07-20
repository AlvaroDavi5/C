#include <stdio.h>
#include <stdlib.h>
#include "listaMat.h"


struct elem
{
	int indice;
	Matriz *matPtr;
	Elemento *prox;
};

struct list
{
	int tam;
	Elemento *topo;
	Elemento *atual;
	Elemento *final;
};


ListaMatriz * iniciarListaMatriz(ListaMatriz *list)
{
	list = (ListaMatriz *) malloc(sizeof(ListaMatriz));

	list->tam = 0;
	list->topo = NULL;
	list->atual = NULL;
	list->final = NULL;

	return list;
}

void adcAoTopo(ListaMatriz *list, Matriz *mat)
{
	Elemento *elem = (Elemento*) malloc(sizeof(Elemento));
	elem->matPtr = mat;

	if (list->topo == NULL)
	{
		list->final = elem;
		elem->prox = NULL;
	}
	else
	{
		elem->prox = list->topo;
	}

	list->topo = elem;
	list->tam += 1;

	Elemento *atual = list->topo;
	for (int i = 0; i < list->tam; i++)
	{
		atual->indice = i;
		atual = atual->prox;
	}
}

void adcAoFinal(ListaMatriz *list, Matriz *mat)
{
	Elemento *elem = (Elemento*) malloc(sizeof(Elemento));

	elem->matPtr = mat;
	elem->prox = NULL;

	if (list->topo == NULL)
	{
		list->topo = elem;
	}
	else
	{
		list->final->prox = elem;
	}

	elem->indice = list->tam;
	list->final = elem;
	list->tam += 1;
}

Elemento * obterElemento(ListaMatriz *list, ptrfCompare funcaoComparar, int pos)
{
	Elemento *atual = list->topo;

	while (atual != NULL)
	{
		if (funcaoComparar(atual->indice, pos) == 0)
		{
			return atual;
		}

		atual = atual->prox;
	}

	return NULL;
}

void inserirProxElemento(ListaMatriz *list, Elemento *elem)
{
	Elemento *novoElemento = (Elemento*) malloc(sizeof(Elemento));

	novoElemento->matPtr = NULL;
	novoElemento->prox = elem->prox;

	if (list->topo == NULL)
	{
		list->topo = novoElemento;
	}
	else
	{
		elem->prox = novoElemento;
	}

	novoElemento->indice = novoElemento->prox->indice;
	Elemento *atual = novoElemento->prox;
	for (int i = novoElemento->indice; i < list->tam; i++)
	{
		atual->indice = i+1;
		atual = atual->prox;
	}
	list->tam += 1;
}

void inserirMatriz(Elemento *elem, Matriz *mat)
{
	elem->matPtr = mat;
}

void deletarElemento(ListaMatriz *list, Elemento *elem)
{
	Elemento *atual = list->topo;

	if (elem == list->topo)
	{
		if (list->topo->prox == NULL)
		{
			list->topo = list->final;
		}
		else
		{
			list->topo = list->topo->prox;
		}
	}
	else
	{
		while (atual != NULL && atual->prox != elem)
		{
			atual = atual->prox;
		}
		if (atual != NULL && atual->prox == elem)
		{
			atual->prox = elem->prox;
			atual->prox->indice = elem->indice;
		}
	}

	destroiMatriz(elem->matPtr);
	free(elem);
	list->tam -= 1;

	Elemento *indiceedElemento = list->topo;
	for (int i = 0; i < list->tam; i++)
	{
		if (indiceedElemento != NULL)
		{
			indiceedElemento->indice = i;
			indiceedElemento = indiceedElemento->prox;
		}
	}
}

void destruirListaMatriz(ListaMatriz *list)
{
	Elemento *atual = list->topo;
	Elemento *prox = NULL;

	while (atual != NULL)
	{
		prox = atual->prox;

		deletarElemento(list, atual);
		atual = prox;
	}

	free(list);
}

void mostrarListaMatriz(ListaMatriz *list)
{
	Elemento *atual = list->topo;

	while (atual != NULL)
	{
		printf("\nMatriz %d:\n", atual->indice);
		imprimeMatriz(atual->matPtr);
		printf("\n");
		atual = atual->prox;
	}
}

int compararData(int d1, int d2)
{
	if (d1 == d2)
	{
		return 0;
	}
	else if (d2 > d1)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}


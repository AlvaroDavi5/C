#ifndef LISTA_MATRIZ_
	#define LISTA_MATRIZ_

	#include "matriz.h"

	// TADs
	typedef int (* ptrfCompare)(int, int);
	typedef struct elem Elemento;
	typedef struct list ListaMatriz;

	// prototipos de funcoes
	ListaMatriz * iniciarListaMatriz(ListaMatriz *list);
	void adcAoTopo(ListaMatriz *list, Matriz *mat);
	void adcAoFinal(ListaMatriz *list, Matriz *mat);
	Elemento * obterElemento(ListaMatriz *list, ptrfCompare funcaoComparar, int pos);
	void inserirProxElemento(ListaMatriz *list, Elemento *elem);
	void inserirMatriz(Elemento *elem, Matriz *mat);
	void deletarElemento(ListaMatriz *list, Elemento *elem);
	void destruirListaMatriz(ListaMatriz *list);
	void mostrarListaMatriz(ListaMatriz *list);
	int compararData(int d1, int d2);

#endif


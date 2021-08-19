#ifndef FILA_H
	#define FILA_H

	#include <stdio.h>
	#include <stdlib.h>
	#include <limits.h>

	#define TRUE 1
	#define FALSE 0

	typedef struct fila_vet FilaVetor;
	typedef struct fila_list FilaLista;
	typedef struct celula Celula;

	// fila vetor
	FilaVetor * criarFilaVetor(int tamanhoAtual);
	void liberarFilaVetor(FilaVetor *fila);
	void enfileirarFilaVetor(FilaVetor *fila, int item);
	int desenfileirarFilaVetor(FilaVetor *fila);
	int estaCheiaFilaVetor(FilaVetor *fila);
	int estaVaziaFilaVetor(FilaVetor *fila);
	void imprimeFilaVetor(FilaVetor *fila);

	// fila lista
	Celula * criarCelula(int valor);
	FilaLista * criarFilaLista(int tamanhoAtual);
	void liberarFilaLista(FilaLista *fila);
	void enfileirarFilaLista(FilaLista *fila, int item);
	void desenfileirarFilaLista(FilaLista *fila);
	int estaVaziaFilaLista(FilaLista *fila);
	void imprimeFilaLista(FilaLista *fila);

#endif


#include <stdio.h>

#define TAM 10

void preenche_vetor(int v[]);
void inverte_a(int v[], int w[]);
void inverte_b(int v[]);
int menor_elemento(int v[]);
void imprime_vetor(int v[]);
void somavetores(int v[], int u[]);

int main()
{
	int vet[TAM], w[TAM], u[TAM], menor;
	char opcao;

	printf("O vetor eh inicializado com os seus proprios indices\n");

	preenche_vetor(vet);
	preenche_vetor(u);
	printf("Vetor de entrada: ");
	imprime_vetor(vet);

	printf("Escolha a operacao com vetor que deseja executar:\n");

	printf("a) inverter as posicoes de seus valores usando um outro vetor para cópia\n");
	printf("b) inverter as posicoes de seus valores usando o mesmo vetor para armazenar o resultado\n");
	printf("c) imprimir o menor elemento de um vetor\n");
	printf("d) imprimir a soma de vetores\n");
	printf("Forneca sua opcao: a, b, c ou d --> ");
	scanf("%c", &opcao);

	switch(opcao)
	{
		case 'a':
			inverte_a(vet,w);
			printf("Vetor invertido: ");
			imprime_vetor(w);
			break;
		case 'b':
			inverte_b(vet);
			printf("Vetor invertido: ");
			imprime_vetor(vet);
			break;
		case 'c':
			menor = menor_elemento(vet);
			printf("O menor elemento do vetor:");
			imprime_vetor(vet);
			printf("eh igual a %d\n", menor);
			break;
		case 'd':
			printf("A soma entre o vetor: ");
			imprime_vetor(vet);
			printf("E o vetor: ");
			imprime_vetor(u);
			somavetores(vet, u);
			printf("Gera o vetor soma:");
			imprime_vetor(u);
			break;
	}

	return 0;
}

//Exemplo a: Definir os elementos de um vetor usando os valores dos seus próprios índices

void preenche_vetor(int v[])
{
	int i;

	for (i=0; i<TAM; i++)
		v[i] = i;
}

//Exemplo b: Inverter os valores de um vetor usando um outro vetor para cópia

void inverte_a(int v[], int w[])
{
	int i;

	for (i=0; i<TAM; i++)
	{
		w[i] = v[TAM - (i+1)];
	}
}

//Exemplo c: Inverter os valores de um vetor usando o mesmo vetor para armazenar o resultado

void inverte_b(int v[])
{
	int i, aux;

	for (i=0; i<TAM/2; i++)
	{
		aux = v[i];
		v[i] = v[TAM - (i+1)];
		v[TAM - (i+1)] = aux;
	}
}

//Exemplo d: Imprimir o menor elemento de um vetor

int menor_elemento(int v[])
{
	int menor, i;

	for (i=0; i<TAM; i++)
	{
		printf("%d ", v[i]);
	}
	printf("\n");

	menor = v[0];
	for (i=1; i< TAM; i++)
		if (v[i] < menor)
			menor = v[i];

	return menor;
}

//Exemplo e: Imprimir a soma de vetores

void somavetores(int v[], int u[])
{
	for (int i = 0; i < TAM; i++)
	{
		u[i] = v[i] + u[i];
	}
}

void imprime_vetor(int v[])
{
	int i;

	for (i=0; i<TAM; i++)
		printf("%d ", v[i]);
	printf("\n");
}

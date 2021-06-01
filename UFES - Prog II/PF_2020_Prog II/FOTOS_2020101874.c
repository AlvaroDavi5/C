//	Alvaro Davi, Eng Comp, UFES, 2020

#include <stdio.h> // Standart Input-Output, biblioteca padrao de entradas e saidas, para funcoes como scanf e printf
#include <stdlib.h> // Standart Library, para alocacao de memoria, conversoes de tipos e outras funcionalidades
#include <math.h> // para operacoes e funcoes matematicas
#include <ctype.h> // para manipulacoes de caracteres
#include <string.h> // para trabalhar com strings
#include <unistd.h> // para comandos e manipulacoes envolvendo SO's da familia UNIX (Linux, GNU, BSD...)
#include <time.h> /* para a fução time() */


#define TRUE 1
#define FALSE 0


typedef struct
{
	int tom_cinza;
	int qtd_repeticoes;
} tCores;


void registraFoto(int f[][30], int n, int m);
void ncores(int f[][30], tCores v[], int n, int m);
void ordena(tCores v[]);
void geraDados(tCores v[], FILE *q);


int main()
{
	int n = 0, m = 0;

	scanf("%d %d", &n, &m);
	int matriz_tons[n][m];
	tCores tonalidades[16]  = {0};

	registraFoto(matriz_tons, n, m);
	ncores(matriz_tons, tonalidades, n, m);

	return 0;
}


void registraFoto(int f[][30], int n, int m)
{
	int i = 0, j = 0, k = 0, l = 0;

	srand(10); // semente definida como 10

	for (i = 0; i < n; i++) // gerando n valores pseudo-aleatórios [pois em computação nada é totalmente aleatório]
	{
		for (j = 0; j < m; j++)
		{
			// gerando valores entre 1 e 16
			int random = (rand() % 16) + 1; // a função rand() só trabalha com números naturais, ou seja, inteiros positivos

			f[i][j] = random; // preenchendo matriz
		}
	}

	// PARA REMOVER
	for (k = 0; k < n; k++) // imprime matriz
	{
		for (l = 0; l < m; l++)
		{
			printf("%d ", f[k][l]);
		}
		printf("\n");
	}
	printf("\n");
}

void ncores(int f[][30], tCores v[], int n, int m)
{
	FILE *q; // ponteiro de arquivo, armazena o endereço das posições do arquivo

	int k = 0, j = 0, i = 0, tons_diferentes = 0, tons = 0;

	for (int t = 0; t < 16; t++) // preencher tonalidades de cinza do vetor v
	{
		v[t].tom_cinza = t+1;
		v[t].qtd_repeticoes = 0;
	}

	for (i = 0; i < n; i++) // varrer toda a matriz
	{
		for (j = 0; j < m; j++)
		{
			for (k = 0; k < 16; k++) // varrer vetor e quantificar ocorrencias de tons
			{
				if (f[i][j] == v[k].tom_cinza) // se a tonalidade na matriz for a mesma que o tom de uma das posicoes do vetor...
				{
					v[k].qtd_repeticoes++; // acrescentar +1 a quantidade de vezes que o tom apareces
					break;
				}
			}
		}
	}

	for (tons = 0; tons < 16; tons++) // verifica tons diferentes
	{
		if (v[tons].qtd_repeticoes != 0)
		{
			tons_diferentes++;
		}
		
	}

	ordena(v);
	geraDados(v, q);
}


// bubbleSort
void ordena(tCores v[])
{
	int memCOR = 0, memQTD = 0, mudanca = TRUE, i = 0, j = 0;

	for (j = (16 - 1); (j >= 1) && (mudanca); j--)
	{
		mudanca = FALSE; // se o valor continuar 'false' na proxima iteracao entao nao houve troca e a funcao termina

		for (i = 0; i < j; i++) // ordena por ocorrencia
		{
			if (v[i].qtd_repeticoes < v[i+1].qtd_repeticoes) // se o valor da posicao i for menor que o valor da posicao i+1
			{
				memCOR = v[i].tom_cinza; // salva temporariamente o valor da posicao i
				memQTD = v[i].qtd_repeticoes;
				v[i].tom_cinza = v[i+1].tom_cinza; // coloca o valor da posicao i+1 na posicao i
				v[i].qtd_repeticoes = v[i+1].qtd_repeticoes;
				v[i+1].tom_cinza = memCOR; // coloca o valor salvo temporariamente na posicao i+1
				v[i+1].qtd_repeticoes = memQTD;
				mudanca = TRUE; // sinalizada a troca para manter o loop
			}
		}
	}
}

void geraDados(tCores v[], FILE *q)
{
	q = fopen("./cores.txt", "w+"); // criar ou sobrescrever arquivo (endereço_arquivo, MODO_abertura), função passando por referência

	// PARA REMOVER
	for (int l = 0; l < 16; l++)
	{
		if (v[l].qtd_repeticoes != 0)
		{
			fprintf(q, "O tom %d aparece %d vezes \n", v[l].tom_cinza, v[l].qtd_repeticoes);
		}
		
	}

	fclose(q);
}

/*

Text | Data | String Literal Pool | Heap | area nao-alocada | Stack | max


Text: contem o codigo do programa e suas constantes. Este segmento e alocado durante a criacao do processo (''exec'') e permanece do mesmo tamanho durante toda a vida do processo.

Data: este segmento e a memoria de trabalho do processo, onde ficam alocadas as variaveis globais e estaticas. Tem tamanho fixo ao longo da execucao do processo.

String Literal Pool: contem os dados das strings armazenados separadamente. Tem tamanho dinamico ao longo da execucao do processo.

Heap: contem blocos de memoria alocadas dinamicamente, a pedido do processo, durante sua execucao. Varia de tamanho durante a vida do processo.

Stack: contem a pilha de execucao, onde sao armazenadas os parametros, enderecos de retorno e variaveis locais de funcoes. Pode variar de tamanho durante a execucao do processo.

----------------------------------------------------------------------------------------------------------

Alocacao Estatica: ocorre quando sao declaradas variaveis globais ou estaticas; geralmente alocadas em Data.

Alocacao Automatica: ocorre quando sao declaradas variaveis locais e parametros de funcoes. O espaco para a alocacao dessas variaveis e reservado quando a funcao e invocada, e liberado quando a funcao termina. Geralmente e usada a pilha (stack);

Alocacao Dinamica: ocorre quando o processo requisita explicitamente um bloco de memoria para armazenar dados, esse bloco precisa ser liberado após o uso;

	Alocacao Semiautomatica: a memoria e alocada dinamicamente, mas sem precisar ser liberada a memoria - pois a liberacao e automatica;

	Alocacao com Alinhamento de Memóra: aloca blocos de memoria em enderecos multiplos de 8 bytes, logo, os enderecos alocados dessa forma possuem endereco 2^n.

*/


#include <stdio.h> // codigo do programa (gravado em Text)
#include <stdlib.h> // nova definicao de NULL


void incrementa(void);
void imprimeBytes(void);
void alocaVetor(void);


int gbl = 15; // variavel global, aloc. estatica (gravada em Data)

int main()
{
	for (int i = 0; i < 5; ++i)
	{
		incrementa();
	}
	imprimeBytes();
	alocaVetor();

	return 0;
}

void incrementa(void)
{
	int local = 2; // variavel local, aloc. automatica (gravada em Stack)
	static int sttc = 12; // variavel local, aloc. estatica (gravada em Data)

	gbl++;
	local++;
	sttc++;

	printf("%d %d %d \n", gbl, local, sttc);
}

void imprimeBytes(void)
{
	int *ptr = 0; // ponteiro [para int] com valor 0 {sem apontar para um endereco} por convencao

	ptr = malloc(2); // alocacao de espaco de memoria de 2 bytes, aloc. dinamica (gravada em Heap)
	ptr = realloc(ptr, sizeof(int)); // realocacao de espaco de memoria para inteiro [4 bytes], aloc. dinamica (gravada em Heap)

	if (ptr == 0) // caso o ponteiro tenha valor zero entao a alocacao nao ocorreu, pois a funcao malloc() retorna 0 nesse caso
		abort();
	else
		printf("Ponteiro apontando para: %p \n", ptr); // a funcao malloc() retorna um endereco para alocacao

	printf("Quantidade de bytes ocupados por um valor inteiro: %lu \n", sizeof(int)); // sizeof() retorna um long-unsigned-int

	free(ptr); // liberando espaco alocado
	ptr = NULL; // apontando ponteiro para void/vazio/0, para evitar erros pois o espaco de memoria o qual ele apontava foi desalocado
}

void alocaVetor(void)
{
	float *vect = 0, *p = 0;

	vect = calloc(15, sizeof(float)); // alocar 15 espacos de float [4 bytes] para o vetor preenchendo-os com zeros, aloc. dinamica com contador (gravada em Heap)
	//vect = malloc(15 * sizeof(float))

	for (int i = 0; i < 10; ++i)
	{
		vect[i] = 1.0 / (i + 1); // preenchendo vetor ate a posicao 10, mesmo ele tendo 15 posicoes
	}

	for (int j = 0; j < 15; j++)
	{
		printf("%f ", vect[j]);
	}

	free(vect);
	vect = NULL;

	p = alloca(1); // alocar 1 byte, aloc. dinamica semiautomatica (gravada em Heap)
	printf("\n%p \n", p);
}

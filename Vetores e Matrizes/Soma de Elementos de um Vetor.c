// EA5 Repl.it

// Ler vetores e retornar indices cuja soma dos elementos resulta em dado numero
// Alvaro Davi, Eng Comp, UFES

/*

Dado um conjunto de entradas N e um número alvo x, retorne os índices de dois números que a soma é igual a x.
O conjunto de elemetos será delimetado por [] e separados por vígula. Após a leitura dos elementos, você vai ler o número alvo x.

Exemplo: [1, 2, 3, 4, 5], 9

*/

#include <stdlib.h>
#include <stdio.h>

void verifSoma(int index, int vetor[], int numAlvo)
{
	int j, k;

	for (int j = 0; j < index-1; j++)
	{
		for (int k = 1; k < index; ++k) // index-1 e k = 1 adcionados para evitar repeticao
		{
			if ((vetor[j] + vetor[k]) == numAlvo)
			{
				printf("%d, %d", j, k);
				break;
			}
		}
	}
}

int main()
{
	char colchete1, colchete2 = ' ';
	int numAlvo, vetor[99]; // de 0 a 98
	int elemento, index = 0;

	scanf("%c", &colchete1); // apenas para ler o '['

	while (colchete2 != ']')
	{
		scanf("%d %c", &elemento, &colchete2); // usar scanf("%d*%d") o faz ignorar quanquer caractere entre os valores que se espera
		vetor[index] = elemento;
		index++;
	}
	scanf(", %d", &numAlvo);

	printf("[");
	verifSoma(index, vetor, numAlvo); // funcao para verificar
	printf("]");

	return 0;
}
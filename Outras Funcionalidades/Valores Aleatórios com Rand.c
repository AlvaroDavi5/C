#include <stdio.h>
#include <stdlib.h> /* para as funções rand() e srand() */
#include <time.h> /* para a fução time() */


int main()
{
	srand(time(NULL));
	/*

	Inicializa o gerador de números aleatórios com o valor da função time(NULL).
	Este por sua vez, é calculado como sendo o total de segundos passados desde 1 de janeiro de 1970 até a data atual.
	Desta forma, a cada execução o valor da "semente" será diferente.

	*/

	for (int i = 0; i < 9; i++) // gerando 9 valores pseudo-aleatórios [pois em computação nada é totalmente aleatório]
	{
		// gerando valores entre 1 e 50
		int aleat = (rand() % 49) + 1;
		printf("%d \n", aleat); // a função rand() só trabalha com números naturais, ou seja, inteiros positivos
	}

	for (int i = 0; i < 3; i++) // gerando 3 valores pseudo-aleatórios [pois em computação nada é totalmente aleatório]
	{
		// gerando valores entre 0 e RAND_MAX
		const random = rand() % RAND_MAX;
		printf("%d \n", random); // a função rand() só trabalha com números naturais, ou seja, inteiros positivos
	}

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 10
#define TRUE 1
#define FALSE 0

void fillArray(int *vet);
void invertArray(int vet[]);
void linearSearchOnArray(int vet[], int num);
void binarySearchOnArray(int vet[], int num);
int insertElementOnArray(int *arr, int size, int num);
int removeElementFromArray(int *vect, int size);
void printArray(int vet[], int size);

int main()
{
	int vet[SIZE], size = SIZE, num;

	fillArray(vet); // como vet ja e dado por ponteiros, entao nao e necessario &

	printArray(vet, SIZE);
	invertArray(vet);

	printf("Digite um numero para ser buscado no vetor em uma busca linear\n");
	scanf("%i", &num);
	linearSearchOnArray(vet, num);

	printf("Digite um numero para ser buscado no vetor em uma busca binaria\n");
	scanf("%i", &num);
	binarySearchOnArray(vet, num); // valida apenas se o vetor estiver ordenado

	int arr[size];
	printf("Digite um numero para ser adicionado a um novo vetor copia\n");
	scanf("%i", &num);
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = vet[i];
	}
	size = insertElementOnArray(arr, size, num);
	printArray(arr, size);

	int vect[size];
	for (int i = 0; i < size; i++)
	{
		vect[i] = arr[i];
	}
	size = removeElementFromArray(vect, size);
	printArray(vect, size);

	return 0;
}


void fillArray(int *vet) /* ao adcionar * na variavel, o parametro nao foi passado por valor e sim por referência */
{
	int list[SIZE];

	for (int n = 0; n < SIZE; n++)
	{
		vet[n] = n + 1;
	}

	srand(time(NULL)); // para valores aleatorios

	for (int l = 0; l < SIZE; l++)
	{
		list[l] = rand() % 100;
	}

	printArray(list, SIZE);
}

void invertArray(int vet[]) // poderia ser usado int* vet como argumento
{
	int arr[SIZE];

	for (int j = 0; j < SIZE; j++)
	{
		arr[j] = SIZE - (vet[j] - 1);
	}

	printArray(arr, SIZE);
}

void linearSearchOnArray(int vet[], int num)
{
	int verif, pos;

	for (int k = 0; k < SIZE; k++)
	{
		if (vet[k] == num)
		{
			verif = TRUE;
			pos = k;
		}
	}

	if (verif == TRUE)
	{
		printf("O numero digitado esta na posicao: %i\n", pos);
	}
	else
	{
		printf("O numero digitado nao esta em qualquer posicao!\n");
	}
}

void binarySearchOnArray(int vet[], int num)
{
	int ini = 0, mid, fin = SIZE;
	int verif = FALSE;

	while (ini <= fin && ! verif)
	{
		mid = (ini + fin) / 2;

		if (num == vet[mid])
		{
			printf("O numero se encontra na posicao %i do vetor.\n", mid);
			verif = TRUE;
		}
		else
		{
			if (num > vet[mid])
				ini = mid + 1;
			else
				fin = mid - 1;
		}
 	}

	if (! verif)
		printf("O numero nao se encontra em qualquer posicao do vetor.\n");
}

int insertElementOnArray(int *arr, int size, int num)
{
	int pos;

	printf("Digite uma posicao de 0 a %d\n", size-1);
	scanf("%d", &pos);

	for (int n = size-1; n >= pos; n--)
	{
		arr[n+1] = arr[n];
	}
	arr[pos] = num;
	size++;

	return size;
}

int removeElementFromArray(int *vect, int size)
{
	int pos, n;

	printf("Digite uma posicao de 0 a %d para ser removida desse novo vetor copia\n", size);
	scanf("%d", &pos);

	for (n = pos; n < size-1; n++)
	{
		vect[n] = vect[n+1];
	}
	vect[n+1] = vect[n] + 1;
	size--;

	return size;
}

void printArray(int vet[], int size)
{
	int cont = 0;

	while (cont < size)
	{
		printf("%i ", vet[cont]);
		cont++;
	}

	printf("\n");
}

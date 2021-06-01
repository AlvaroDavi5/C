
/*

	Codigo criado por Alvaro Davi S. Alves, Matricula: 2020101874
	
	Para a 11a tarefa da disciplina de Matematica para Engenharia I

*/


#include <stdio.h> // biblioteca padrao de input e output
#include <stdlib.h> // biblioteca padrao de tipos e funcoes built-in


// prototipos de funcoes
float funcao_a(float a, float b, int n);
float funcao_b(float a, float b, int n);


int main()
{
	// variaveis declaradas e inicializadas
	char letra=' ';
	int n=0;
	float a=0.00, b=0.00, res=0.00;

	// interface humano-computador (CLI emulado em shell)
	printf(" --------- CALCULO DE INTEGRAL --------- \n\n");
	printf(" a)f(x) = x/7 + 0,5\n b)f(x) = 0.1x² - 2\n\n");
	printf("Selecione a funcao pela letra: ");
	scanf("%c", &letra);

	switch(letra) // para cada letra, uma funcao, o resultado depende da funcao escolhida
	{
		case 'a':
			printf("Selecione os valores de A e B para o intervalo [A, B]: ");
			scanf("%f %f", &a, &b);
			printf("Selecione a quantidade de divisoes para o valor de N: ");
			scanf("%d", &n);
			res = funcao_a(a, b, n); // para a funcao a)
			break;
		case 'b':
			printf("Selecione os valores de A e B para o intervalo [A, B]: ");
			scanf("%f %f", &a, &b);
			printf("Selecione a quantidade de divisoes para o valor de N: ");
			scanf("%d", &n);
			res = funcao_b(a, b, n); // para a funcao b)
			break;
		default:
			printf("\n\nOpcao invalida, SAINDO...\n");
			exit(0); // sai do programa se for escolhida uma letra inexistente
			break;
	}

	printf("\n");
	printf("A resposta é: %f", res);

	return 0;
}


float funcao_a(float a, float b, int n)
{
	float res=0.00, xi=0.00;
	float dx = (b-a)/n;

	for (int i = 1; i <= n; i++) // para i variando de 1 ate n...
	{
		xi = a + i*dx; // valor de x em i
		res += dx * (xi/7 + 0.5); // somatorio aplicando a funcao
	}

	return res;
}

float funcao_b(float a, float b, int n)
{
	float res=0.00, xi=0.00;
	float dx = (b-a)/n;

	for (int i = 1; i <= n; i++) // para i variando de 1 ate n...
	{
		xi = a + i*dx; // valor de x em i
		res += dx * (0.1*(xi*xi) - 2); // somatorio aplicando a funcao
	}

	return res;
}


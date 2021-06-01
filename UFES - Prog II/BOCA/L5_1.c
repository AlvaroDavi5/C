/*

Ler N notas e calcular Menor, Maior, Media, Desvio Padrão, quantidade Acima da Media, Quantidade Reprovados

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n, menor, maior, qtdMaiorQMedia = 0, qtdReprovados = 0;
	float somaNotas = 0, somatorio = 0, media = 0.00, desviopadrao = 0.00;

	scanf("%d", &n);

	int notasAlunos[n];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &notasAlunos[i]);
		somaNotas += notasAlunos[i];
	}
	media = somaNotas / n;


	menor = notasAlunos[0];
	maior = notasAlunos[0];
	for (int j = 0; j < n; j++)
	{
		if (notasAlunos[j] < menor)
		{
			menor = notasAlunos[j];
		}
		if (notasAlunos[j] > maior)
		{
			maior = notasAlunos[j];
		}

		if (notasAlunos[j] > media)
		{
			qtdMaiorQMedia++;
		}
		if (notasAlunos[j] < 70)
		{
			qtdReprovados++;
		}
	}


	for (int k = 0; k < n; k++)
	{
		somatorio += (notasAlunos[k] - media)*(notasAlunos[k] - media);
	}
	desviopadrao = sqrt(somatorio / n);


	printf("MENOR:%d, ", menor);
	printf("MAIOR:%d, ", maior);
	printf("MEDIA:%.2f, ", media);
	printf("STD:%.2f, ", desviopadrao);
	printf("ACIMA_MEDIA_CONC:%d, ", qtdMaiorQMedia);
	printf("REPROV:%d", qtdReprovados);

	return 0;
}

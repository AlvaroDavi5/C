//	Alvaro Davi, Eng Comp, UFES, 2020


#include <stdio.h> // Standart Input-Output, biblioteca padrao de entradas e saidas, para funcoes como scanf e printf
#include <stdlib.h> // Standart Library, para alocacao de memoria, conversoes de tipos e outras funcionalidades
#include <math.h> // para operacoes e funcoes matematicas
#include <ctype.h> // para manipulacoes de caracteres
#include <string.h> // para trabalhar com strings
#include <unistd.h> // para comandos e manipulacoes envolvendo SO's da familia UNIX (Linux, GNU, BSD...)


#define TAM 40

void leStrings(char v[], char s[]);
int ocorre(char v[], char s[]);
void ocorrencias(char v[], char s[], int ocorrencias);


int posicoes[TAM];


int main()
{
	int numOcorrencias = 0;
	char string1[TAM], string2[TAM];

	leStrings(string2, string1);
	numOcorrencias = ocorre(string2, string1);
	ocorrencias(string2, string1, numOcorrencias);

	return 0;
}



void leStrings(char v[], char s[])
{
	scanf("%[^\n]", s);
	scanf(" %[^\n]", v);

	for (int i = 0; i < TAM; i++)
	{
		posicoes[i] = -1;
	}
}


int ocorre(char v[], char s[])
{
	int i, j = 0, ocorre = 0, pos = 0, tamS = strlen(s), verif = 0;

	for (i = 0; i < TAM; i++)
	{
		int k = i;
		int l = i;
		for (j = j; j < tamS; j++)
		{
			if (s[j] == v[k])
			{
				verif++;
			}

			if (verif == tamS)
			{
				ocorre++;
				posicoes[pos] = l;
				pos++;
				j = i+1;
				break;
			}

			k++;
		}
	}

	if (ocorre == 0)
		return -1;
	else
		return ocorre;
}

/*

strstr(sFrase, "to");

for(i=0;i<strlen(S1);i++)
{
    if(S2[0]==S1[i])
	{
		for(j=0;j<strlen(S2)-1;j++)
		{
        	if(S2[j]==S1[i++])
                    c++;
                }
            }
            if(c==strlen(S2)){
                break;
        }

*/


void ocorrencias(char v[], char s[], int ocorrencias)
{
	if (ocorrencias == -1)
	{
		printf("A string %s nao ocorre em %s", s, v);
	}
	else
	{
		if (ocorrencias == 1)
			printf("%d ocorrencia da string %s em %s a partir da posicao %d", ocorrencias, s, v, posicoes[0]);
		else
		{
			printf("%d ocorrencias da string %s em %s a partir das posicoes %d", ocorrencias, s, v, posicoes[0]);
			for (int i = 0; (i < ocorrencias) && (i != -1); i++)
			{
				printf(" e %d", posicoes[i+1]);
			}
		}
	}
}

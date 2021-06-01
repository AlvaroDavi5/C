//	Alvaro Davi, Eng Comp, UFES, 2020


// inclusao de bibliotecas para funcoes ja existentes
#include <stdio.h> // Standart Input-Output, biblioteca padrao de entradas e saidas, para funcoes como scanf e printf
#include <stdlib.h> // Standart Library, para alocacao de memoria, conversoes de tipos e outras funcionalidades
#include <math.h> // para operacoes e funcoes matematicas
#include <ctype.h> // para manipulacoes de caracteres
#include <string.h> // para trabalhar com strings
#include <unistd.h> // para comandos e manipulacoes envolvendo SO's da familia UNIX (Linux, GNU, BSD...)


int main()
{

  //Exemplo de entrada
	// 002 002 9estudei o 0911
	scanf("%d ", ...); //002
	scanf("%d ", ...); //002
	char c;
	scanf("%c",&c); //9
	c -= '0'; //Vai obter o tamanho da msg corretamente
  //ppega os 9 caracteres
	for(i=0; i<9; i++){
		char c;
		scanf("%c", &c);  //estudei o
		 ....
	}
  //como nem sempre os 9 caracteres fazem parte da msg, adiciona \0 no final
	//suamsg[c]  = '\0';

	scanf("%d", ...); //0911


	return 0;

}

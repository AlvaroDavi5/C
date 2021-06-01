/*

Apresentar datas de um intervalo de datas

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "datafunc.h" 

int main()
{
	tData data;
	tData dataIni;
	tData dataFim;

	dataIni = lerData();
	dataFim = lerData();

	for (data = dataIni; !ehIgual(data, dataFim); data = aumentaDMA(data)) // !ehIgual() verifica se NAO e igual, pois o operador logico ! inverte os valores 0 e 1 (false e true)
	{
		imprimeData(data);
		printf("\n");
	}

	return 0;
}
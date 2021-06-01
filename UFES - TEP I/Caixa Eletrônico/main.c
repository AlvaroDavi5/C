#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "conta.h"


int main()
{
	srand(time(NULL));

	int qtdContas = 0;
	Conta **contas = (Conta **) malloc(sizeof(Conta *));

	operacao(contas, qtdContas);

	deletarTodasContas(contas, qtdContas);

	return 0;
}

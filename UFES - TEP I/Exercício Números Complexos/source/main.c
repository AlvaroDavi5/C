#include <stdio.h>
#include <stdlib.h>
#include "../include/complexos.h"


int main()
{
	D_Complexo_pt pval1=NULL, pval2=NULL, pval3=NULL;

	pval1 = atribuirComplexo(-2.04, 3.05);
	pval2 = atribuirComplexo(5.00, -7.001);

	pval3 = somarComplexo(pval1, pval2);

	exibirComplexo(pval3);

	return 0;
}

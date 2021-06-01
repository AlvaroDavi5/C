#include <stdio.h>
#include <stdlib.h>
#include "../include/complexos.h"


struct D_Complexo_s
{
	double im;
	double re;
};
typedef struct D_Complexo_s D_Complexo_t;


D_Complexo_pt atribuirComplexo(double real, double imaginario)
{
	D_Complexo_t *pt_valor = NULL;
	pt_valor = (D_Complexo_t *)malloc(sizeof(D_Complexo_t));
	pt_valor->im = imaginario;
	pt_valor->re = real;

	return pt_valor;
}

void exibirComplexo(D_Complexo_pt pt_valor)
{
	if (pt_valor->im > 0)
		printf("%f + %f \n", pt_valor->re, pt_valor->im);
	if (pt_valor->im < 0)
		printf("%f + %f \n", pt_valor->re, -pt_valor->im);
	else
		printf("%f \n", pt_valor->re);
}

D_Complexo_pt somarComplexo(D_Complexo_pt pt_val1, D_Complexo_pt pt_val2)
{
	D_Complexo_t *pt_valor = NULL;
	pt_valor = (D_Complexo_t *)malloc(sizeof(D_Complexo_t));
	pt_valor->im = pt_val1->im + pt_val2->im;
	pt_valor->re = pt_val1->re + pt_val2->re;

	return pt_valor;
}

double raiz(double numero)
{
	double b=numero, a=1, precisao=0.000001;
	while ((b-a) >= precisao)
	{
		b = (a+b)/2;
		a = numero / b;
	}

	return b;
}

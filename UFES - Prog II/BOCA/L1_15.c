/*

Verifica se ímpar ou par por 3 casas decimais

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <math.h>

int main()
{
	int ord, num;
    int cen, dez, uni;

	scanf("%d %d", &num, &ord);

    uni = num % 10; // 134 --> 4
    cen = num / 100; // 134 --> 1
    dez = (num - uni - (cen*100)) / 10; // (134 -4 -100)/10 --> 3

    switch (ord)
    {
    case 1:
        num = uni;
        break;
    case 2:
        num = dez;
        break;
    case 3:
        num = cen;
        break;
    default:
        // Caso não seja de 1 a 3, dará erro :-(
        break;
    }

    if (num % 2 == 0)
    {
        printf("PAR");
    }
    else
    {
        printf("IMPAR");
    }

    return 0;
}
/*

Somar o dobro de 2 numeros reais

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <math.h>

int main()
{
    float X, Y, Res;

    scanf("%f %f", &X, &Y);
    Res = 2*X + 2*Y;
    printf("%.2f",Res);
    return 0;
}
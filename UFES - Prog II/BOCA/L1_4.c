/*

Calcular área do círculo e raio de um círculo com metade da área, dado o raio

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <math.h>

#define PI 3.141592 // const ou #define podem ser usadas para constantes

float main()
{
    float raioC, Area, rMetA;

    scanf("%f", &raioC);
    Area = PI*(raioC*raioC);
    rMetA = (sqrt((Area/2)/PI));
    printf("%.2f %.2f",Area, rMetA);
    return 0;
}
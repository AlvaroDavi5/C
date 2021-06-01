/*

Calcular perímetro do retângulo

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <math.h>

int main()
{
    float Xie, Xsd, Yie, Ysd, Base, Alt, Perim;

    scanf("%f %f %f %f", &Xie, &Yie, &Xsd, &Ysd);
    Base = Xsd - Xie;
    Alt = Ysd - Yie;
    Perim = 2 * (Base + Alt);
    printf("%.2f", Perim);
    return 0;
}
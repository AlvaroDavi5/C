/*
ler Xie, Xsd, Yie, Ysd
Base = Xsd - Xie
Alt = Ysd - Yie
Perim = 2*(Base + Alt)
*/

#include <stdio.h>
#include <math.h>

int main()
{
    float Xie, Xsd, Yie, Ysd;
    int Base, Alt, Perim;

    printf("Digite o valor de X do canto Inferior Esquerdo:");
    scanf("%f", &Xie);
    printf("Digite o valor de Y do canto Inferior Esquerdo:");
    scanf("%f", &Yie);
    printf("Digite o valor de X do canto Superior Direito:");
    scanf("%f", &Xsd);
    printf("Digite o valor de Y do canto Superior Direito:");
    scanf("%f", &Ysd);
    Base = Xsd - Xie;
    Alt = Ysd - Yie;
    Perim = 2 * (Base + Alt);
    printf("O perímetro do retângulo é:\n %i",Perim);
    return 0;
}
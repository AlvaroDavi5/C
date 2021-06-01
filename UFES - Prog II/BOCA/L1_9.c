/*

Converter de minúscula para maúscula

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char letra;
    int letraM;

    scanf("%c", &letra);

    if ((int)letra >= 97 && (int)letra <= 122)
    {
        letraM = (int)letra - 32;
        printf("%c(%i)", letraM, letraM);
    }
    
    if ((int)letra >= 65 && (int)letra <= 90)
    {
        printf("A letra deve ser minuscula!");
    }

    if ((int)letra < 65 || (int)letra > 90 && (int)letra < 97 || (int)letra > 122)
    {
        printf("Nao e letra!");
    }
    
    
    return 0;
}
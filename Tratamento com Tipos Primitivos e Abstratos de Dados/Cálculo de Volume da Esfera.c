/*
ler raioC e PI
Vc = (4*PI*(raioC³))/3
mostrar Vc
*/

#include <stdio.h>

#define PI 3.14159

float main()
{
    float raioC;
    float result;

    printf("Digite o valor do raio:");
    scanf("%f", &raioC);
    printf("O raio digitado foi:\n %f \n",raioC);
    result = (4*PI*(raioC*raioC*raioC))/3;
    printf("O volume do círculo é:\n %f \n",result);
    return 0;
}
/*
ler CO e CA
Hip = raizq(CO² + CA²)
mostrar Hip
*/

#include <stdio.h>
#include <math.h>

float main()
{
    int CA, CO;
    double Hip;

    printf("Digite o valor do cateto oposto:");
    scanf("%d", &CO);
    printf("Digite o valor do cateto adjacente:");
    scanf("%d", &CA);
    Hip = sqrt((CO*CO)+(CA*CA));
    printf("O valor da hipotenusa é: %.12lf \n",Hip);
    return 0;
}

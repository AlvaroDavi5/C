/*Programa para conversão de temperatura de Celsius para Fahrenheit*/

#include <stdio.h>


float converte (float c) {
    float f; // declaração de uma variável float
    f = 1.8*c + 32;
    return f;
}

/* Função principal */
int main (void)
{
    float t1;
    float t2;
    // como testar a função: t2 = converte(30.0);
    /* mostra mensagem para o usuário */
    printf("Digite a temperatura em Celsius: ");
    /* captura valor entrado via teclado */
    scanf("%f", &t1);
    /* converte o valor, chamando a função auxiliar */
    t2 = converte(t1); // ou printf(“Resultado=%f”, converte(t1));
    /* exibe resultado */
    printf("Temperatura em Fahrenheit: %f\n", t2);

    return 0;
}

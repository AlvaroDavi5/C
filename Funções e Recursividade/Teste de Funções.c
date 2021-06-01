#include <stdio.h>
#include <stdlib.h>

// ------------------------------------- Função de Soma Sobre Multiplicação de 2 Termos -------------------------------------

// Criada antecipadamente a função para calcular
float somMult(float n1, float n2) // Parametros da função, espaços para variáveis a serem lidas
{
    float res = (n1 + n2) / (n1 * n2);

    return (res); // Resultado retornado no final do cálculo
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void potSqr(float n1, float n2); // Protótipo da função 'potSqr()', para buscá-la em qualquer trecho do código e prepará-la

// ################################# Função Principal, OBRIGATÓRIA #################################

int main(void) // Retorna um número inteiro ao sistema, para relatar se houve erros ou não e recebe void (nada) como parâmetro
{
    float n1, n2, num1, num2, res;

    printf("Digite um valor...\n");
    scanf("%f", &n1);
    printf("Digite outro valor...\n");
    scanf("%f", &n2);

    res = somMult(n1, n2); // 'res' recebe o resultado retornado pela função chamada

    printf("(%.3f + %.3f) / (%.3f * %.3f) = %.2f \n", n1, n2, n1, n2, res);

    potSqr(n1, n2); // Argumentos da função, passadas as variáveis a serem usadas

    return 0;
}

// ------------------------------------- Função de Potenciação ao Quadrado -------------------------------------


void potSqr(float n1, float n2) /* Tipo de função definida como 'void', portanto não retorna qualquer valor */
{
    float num1 = (n1 * n1);
    float num2 = (n2 * n2);
    printf("N1² = %.2f || N2² = %.2f \n", num1, num2);

    return;
}

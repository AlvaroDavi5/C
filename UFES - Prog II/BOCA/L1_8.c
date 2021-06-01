/*

Diferenciar vogais de não-vogais

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char letra; //letra a ser digitada
    char vogais[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}; //conjunto de vogais
    int i = 0; //variável lógica
    int n = 0; //contador de vetores

	scanf("%c", &letra); //ler a letra digitada

    while (i == 0 && n < 10) //enquanto 'i' for 0 e 'n' estiver dentro do vetor [0..9]
    {
        if (vogais[n] == letra) //se um dos elementos do vetor (todos vão ser testados) for igual à letra digitada
        {
            i = 1;
        }
        n++;
    }

    if (i == 1)
    {
        printf("Vogal");
    }

    else
    {
        printf("Nao vogal");
    }

    return 0;
}

/*
-------------------------Para 5 interações com o usuário----------------------------

int i;

for (i = 0; i < 5; i++)
{
    if (tolower(letra)) == vogais[i];
    {
        return -99;
        break;
    }
}

------------------------------------------------------------------------------------
*/
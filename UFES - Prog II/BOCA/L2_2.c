/*

Mostrar múltiplos de 3, 4 e 7 de um intervalo

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>

int main()
{
    int i, n, m;

    scanf("%i %i", &n, &m);

    for (i = n+1; i < m; i++)
    {
        if (i % 3 == 0  || i % 4 == 0 || i % 7 == 0)
        {
            printf("%i ", i);
        }
    }

    return 0;
}
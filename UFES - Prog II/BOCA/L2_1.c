/*

Mostrar pares de um intervalo

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>

int main()
{
    int m, n, i=0;

    scanf("%i %i", &m, &n);

    if (m >= n)
    {
        i = n + 1;
    }
    
    else
    {
        i = m + 1;
    }

    printf("RESP:");

    while (i < m || i < n)
    {
        if (i % 2 == 0)
        {
            printf("%i ", i);
        }

        i++;
    }

    return 0;
}
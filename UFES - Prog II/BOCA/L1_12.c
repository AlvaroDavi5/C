/*

Ordenar numeros crescentemente

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int n1, n2, n3;

    scanf("%i %i %i", &n1, &n2, &n3);

    if (n1 > n2 && n1 > n3)
    {
        if (n2 > n3)
        {
            printf("N3 = %i, N2 = %i, N1 = %i", n3, n2, n1);
        }
        if (n3 > n2)
        {
            printf("N2 = %i, N3 = %i, N1 = %i", n2, n3, n1);
        }
    }

    if (n2 > n1 && n2 > n3)
    {
        if (n1 > n3)
        {
            printf("N3 = %i, N1 = %i, N2 = %i", n3, n1, n2);
        }
        if (n3 > n1)
        {
            printf("N1 = %i, N3 = %i, N2 = %i", n1, n3, n2);
        }
    }

    if (n3 > n1 && n3 > n2)
    {
        if (n1 > n2)
        {
            printf("N2 = %i, N1 = %i, N3 = %i", n2, n1, n3);
        }
        if (n2 > n1)
        {
            printf("N1 = %i, N2 = %i, N3 = %i", n1, n2, n3);
        } 
    }

    return 0;
}
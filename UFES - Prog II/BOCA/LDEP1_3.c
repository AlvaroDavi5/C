/*

Lista de 2 a n os múltiplos de 2 e 3

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>

int main()
{
    int n, i = 1;

    scanf("%d", &n);

    while(i < n)
    {
        if (i % 2 == 0)
        {
            printf("%d ", i);
        }
        else if (i % 3 == 0)
        {
            printf("%d ", i);
        }
        
        i++; // i = i + 1, i += 1 ou i++
    }

    return 0;
}

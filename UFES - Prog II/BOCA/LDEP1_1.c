/*

Faz a soma de 2 inteiros de forma repetida

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, d;
    
    a = 0;
	scanf("%d", &d);
    
    while(a < d)
    {
        scanf("%d %d", &b, &c);
        printf("%d\n", b + c);
        a++;
    }

    return 0;
}

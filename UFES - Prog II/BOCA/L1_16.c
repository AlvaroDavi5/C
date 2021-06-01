/*

Cálculo da quantidade mínima de cédulas usadas para pagamento

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>

    // COM DESVIOS CONDICIONAIS

int main()
{
    int valor,n500=0,n100=0,n50=0,n10=0,n5=0,n1=0,cedulas=0;

    scanf("%d",&valor);

    if (valor>=500)
    {
        n500=valor/500;
        printf("%d (500), ",n500);
    }
        valor=valor%500;
    if (valor>=100)
    {
        n100=valor/100;
        printf("%d (100), ",n100);
    }
        valor=valor%100;
    if (valor>=50)
    {
        n50=valor/50;
        printf("%d (50), ",n50);
    }
        valor=valor%50;
    if (valor>=10)
    {
        n10=valor/10;
        printf("%d (10), ",n10);
    }
        valor=valor%10;
    if (valor>=5)
    {
        n5=valor/5;
        printf("%d(5) ",n5);
    }
        valor=valor%5;
    if (valor>=1)
    {
        n1=valor;
        printf("%d(1)",n1);
    }

    cedulas=n500+n100+n50+n10+n5+n1;

    printf(". Total: %d cedulas.",cedulas);

    return 0;
}

/*

    COM LACOS DE REPETICAO

#include <stdio.h>

int main()
{
    int value, i, actualNote = 0, cont = 0, total = 0;
    int notes[6] = {500, 100, 50, 10, 5, 1};

    scanf("%d", &value);

    for (i = 0; i < 6; i++)
    {
        actualNote = notes[i];

        while (value >= actualNote)
        {
            value -= actualNote;
            cont++;
        }

        if (cont != 0)
        {
            if (i < 5)
            {
                printf("%i (%i), ", cont, actualNote);
            }

            if (i == 5)
            {
                printf("%i(%i). ", cont, actualNote);
            }
        }

        total += cont;
        cont = 0;
    }

    printf("Total: %i cedulas.", total);

    return 0;
}

*/
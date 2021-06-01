/*

Converter temperatura

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <math.h>

int main()
{
	int temp;
    char scal;
    float NewTemp;


    //ler Temperatura e Escala
	scanf("%i %c", &temp, &scal);

    //Fahrenheit ==>> Celsius
    if (scal == 'f' || scal == 'F')
    {
        NewTemp = (temp-32.00)*5.00/9.00;
        printf("%.2f (C)", NewTemp);
    }


    //Celsius ==>> Fahrenheit
    if (scal == 'c' || scal == 'C')
    {
        NewTemp = (temp*9.00/5.00)+32.00;
        printf("%.2f (F)", NewTemp);
    }


    return 0;
}

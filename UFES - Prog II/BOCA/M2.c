/*

Lê 1 número real e imprime o mesmo como inteiro e real

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <math.h>

int main()
{
    float Num, FNum;
    int INum;

    //printf("Insira um número Real... \n");
    scanf("%f", &Num);
    INum = (int)Num;
    FNum = Num - (int)Num;
    printf("INTEIRO:%i,REAL:%.2f", INum, FNum);
    return 0;
}

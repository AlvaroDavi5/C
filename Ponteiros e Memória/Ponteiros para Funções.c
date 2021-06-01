#include <stdio.h>
#include <stdlib.h>


// declaracao de ponteiro para funcao que recebe int e retorna float
float (*fgIrF)(int);
typedef int (*fgIrI)(int, int);


// decaracao de funcoes com mesmos tipos de parametros e retorno
float parseToFloat(int num)
{
	return (float)num;
}

float square(int num)
{
	return (float)(num*num);
}

int addition(int n1, int n2)
{
	return n1 + n2;
}

int subtract(int n1, int n2)
{
        return n1 - n2;
}

int calcule(fgIrI operation, int n1, int n2)
{
	return operation(n1, n2);
}


int main()
{
	int num = 5;

	fgIrF = parseToFloat;
	printf("Parsing %d to float: %f \n", num, fgIrF(num));
	fgIrF = square;
	printf("%d squared is: %f \n", num, fgIrF(num));

	printf("3 + 2 = %i \n", calcule(addition, 3, 2));
	printf("3 - 2 = %i \n", calcule(subtract, 3, 2));

	return 0;
}


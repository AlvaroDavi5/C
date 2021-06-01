#include <stdio.h>
#include <stdlib.h>


// macros
#define convertToString(str) #str // o operador # [stringize] coloca o token de argumento entre aspas duplas ainda na fase de pre-processamento
#define concat(a, b) a##b // o operador ## [token-pasting] cola o token de argumento e pode concatenar tokens ainda na fase de pre-processamento


int main()
{
	int ab = 15;

	printf(convertToString(Oiiii galera! \n));
	printf("%d \n", concat(a, b));

	return 0;
}

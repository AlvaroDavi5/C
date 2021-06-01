#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// RAII macro que sera transformada no pre-processamento (# transforma argumento em string, ## concatena dois argumentos)
#define RAII_VARIABLE(vartype,varname,initval,dtor) \
	void _dtor_ ## varname (vartype * v) { dtor(*v); } \
	vartype varname __attribute__((cleanup(_dtor_ ## varname))) = (initval)


void RAII_execute()
{
	RAII_VARIABLE(char *, myFavBook, (char*) malloc(20 * sizeof(char)), free); // params: tipo, identificador, valor inicial, funcao quando a variavel sair do escopo

	strcpy(myFavBook, "The Lord of the Rings");
	printf("My favorite book is: %s \n", myFavBook);
}


int main()
{
	RAII_execute();

	return 0;
}

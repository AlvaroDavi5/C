#include <stdio.h>
#include <stdlib.h>

int main()
{
	char string[100]  = "Hello World! \n"; // array com 100 espaços
	// string[100] = {'O', 'l', 'a', ',', 'm', 'u', 'n', 'd', 'o', '!'}; nao seria uma string, e sim um array de char

	fputs(string, stdout); // printar no terminal (arquivo padrão stdout)

	return 0;
}

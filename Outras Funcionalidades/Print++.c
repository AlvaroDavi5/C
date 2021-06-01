#include <stdio.h>

// alem do printf e do fprintf

void demonstrarSNprintf()
{ 
	char buffer[50];
	char *s = "H1, 1M 4 M4CH1N3! :¬>";

	// contando caracteres da string, armazenando a string no buffer e o tamanho da string em uma variavel
	int j = snprintf(buffer, 18, "%s\n", s); // argumento numerico corresponde ao parametro de limitador de string

	// imprimindo a string e o contador de caracteres
	printf("String: '%s' \nCharacter count = %d \n", buffer, j);
} 

void demonstrarSprintf()
{
	char buffer[50];
	int a = 10, b = 20, c;
	c = a + b;

	// a string "sum of 10 and 20 is 30" e armazenada no buffer em vez de ser imprimida no stdout
	sprintf(buffer, "Sum of %d and %d is %d \n", a, b, c);

	printf("%s", buffer);
}


int main()
{
	demonstrarSNprintf();
	demonstrarSprintf();
	
	return 0;
}


#include <stdio.h>
#include <stdlib.h>

int main()
{
	char caractere = '\0';
	int caracASCII = 0;

	printf("Digite um caractere: ");
	scanf("%c", &caractere);

	caracASCII = (int)caractere; // cast ou conversao
	printf("O caractere %c em ASCII eh: %d\n", caractere, caracASCII);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int b, o, d, hd;
	int bin, oct, dec, hex;


	b = 0b1111011; //bin
	o = 0173;	//oct
	d = 123;	//dec
	hd = 0x7B;	//hexd

	printf(" %d %d %d %d \n", b, o, d, hd); // O printf (com %dec) interpreta como decimal as bases: binário, octal, decimal e hexacecimal
	printf(" %i %i %i %i \n", b, o, d, hd); // O printf (com %int) também interpreta como decimal as bases: binário, octal, decimal e hexacecimal


	printf("Digite 3 valores:   Octal  Decimal  Hexadecimal \n");
	scanf("%i %i %i", &oct, &dec, &hex); // O scanf (com %int) não pode interpretar a base: binário
	printf(" %i %i %i \n", oct, dec, hex);

	printf("Digite 1 valor:   Decimal \n");
	scanf("%d", &dec); // O scanf (com %dec) não pode interpretar as bases: binário, octal e hexacecimal
	printf(" %d \n", dec);

	return 0;
}

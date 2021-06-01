#include <stdio.h>

int main()
{
	float num, square;

	printf("Por favor, digite 1 número real\n");
	scanf("%f", &num);

	square = num * num;

	printf("%.2f \n", square);

	return 0;
}
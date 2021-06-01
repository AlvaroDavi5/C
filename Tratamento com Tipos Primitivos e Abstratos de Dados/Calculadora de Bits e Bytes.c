#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
	int numbyte = 0;

	printf("Digite o número de bytes: ");
	scanf("%d", &numbyte);

	printf("%d byte(s) correspondem a %d bits, pois 1B = 8b. \n", numbyte, 8*numbyte);
	printf("%d bits fornecem %f possibilidades de numeros, pois 2^8 = 256. \n", 8*numbyte, pow(2, 8)*numbyte);
	printf("\n");

	return 0;
}


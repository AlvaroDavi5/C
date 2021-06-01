#include <stdio.h>

int main()
{
	float A, B, tempA, tempB;

	printf("Por favor, digite 2 números\n");
	scanf("%f %f", &A, &B);

	tempA = A;
	tempB = B;
	A = tempB;
	B = tempA;

	printf("%.2f %.2f \n", A, B);

	return 0;
}
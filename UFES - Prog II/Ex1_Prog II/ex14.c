#include <stdio.h>

int main()
{
	float A, B;

	printf("Por favor, digite 2 numeros \n");
	scanf("%f %f", &A, &B);

	if (A > B)
	{
		A = A - B;
		B = A + B;
		A = B - A;
	}

	else if (A < B)
	{
		A = B - A;
		B = B - A;
		A = A + B;
	}

	printf("%.2f %.2f \n", A, B);

	return 0;
}
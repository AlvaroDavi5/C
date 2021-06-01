#include <stdio.h>

int fatorialCalc(int n);

int main()
{
	int num, i;

	printf("Digite um numero para calcular seu fatorial: ");
	scanf("%d", &num);

	printf("\nFatorial:\n");
	for (i = num; i > 1; i--)
	{
		printf("%d*", i);
	}
	printf("%d!", i);
	printf(" = %d", fatorialCalc(num));

}

int fatorialCalc(int n)
{
	if (n == 0)
		return 1;
	else
		return n * fatorialCalc(n-1);
}

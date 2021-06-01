#include <stdio.h>

int Fibbonacci(int n);

int main()
{
	int num, i, a = 0, b = 1;

	printf("Digite um numero para ver a sequencia o numero de mesma ordem que ele: ");
	scanf("%d", &num);

	printf("Sequencia:\n");
	for (i = 0; i < num; i++)
	{
		printf("%d ", Fibbonacci(i+1));
	}

}

int Fibbonacci(int n)
{
	if (n == 1 || n == 2)
		return 1;

	else
		return Fibbonacci(n-1) + Fibbonacci(n-2);
}

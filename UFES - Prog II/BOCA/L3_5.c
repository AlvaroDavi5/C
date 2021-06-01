/*

Verificar numero 'abcd' com propriedade (ab) + (cd) == (ef) e (ef*ef) == (abcd) em um intervalo ]n, m[

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Propriedade(int num);

int main()
{
	int n, m, num;

	scanf("%d %d", &n, &m);

	if (n > 1000 && m < 9999)
	{
		for (int i = n; i < m; i++)
		{
			num = i + 1;

			if (Propriedade(num))
			{
				printf("%d\n", num);
			}
		}
	}

	return 0;
}

int Propriedade(int num)
{
	int ab, cd, ef;

	cd = num % 100;
	ab = (num - cd) / 100;
	ef = ab + cd;

	return ((ef * ef) == num) ? 1 : 0; // operador ternario
}

/*

Verificar numero 'abcd' com propriedade (ab) + (cd) == (ef) e (ef*ef) == (abcd) em um intervalo ]n, m[

Alvaro Davi, Eng Comp UFES, 2020

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n, m;
	int abcd, ab, cd, ef;

	scanf("%d %d", &n, &m);

	if (n > 1000 && m < 9999)
	{
		for (int i = n; i < m; i++)
		{
			abcd = i + 1;
			cd = abcd % 100;
			ab = (abcd - cd) / 100;
			ef = ab + cd;

			if ((ef * ef) == abcd)
			{
				printf("%d\n", abcd);
			}
		}
	}

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char letra;

	scanf("%c", &letra);

	while (1)
	{
		if (letra == '.')
		{
			printf(".");
			break;
		}
		else
		{
			if (letra == '0' || letra == '1' || letra == '2' || letra == '3' || letra == '4' || letra == '5' || letra == '6' || letra == '7' || letra == '8' || letra == '9')
			{
				printf("*");
			}
			else
			{
				printf("%c", letra);
			}
		}
		scanf("%c", &letra);
	}


	return 0;
}

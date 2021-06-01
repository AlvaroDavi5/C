#include <stdio.h>

int main()
{
	float quilo_hora, metro_sec;

	printf("Insira a velocidade em Km/h \n");
	scanf("%f", &quilo_hora);

	metro_sec = quilo_hora / 3.6;
	printf("%.2f \n", metro_sec);

	return 0;
}
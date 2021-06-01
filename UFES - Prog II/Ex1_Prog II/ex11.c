#include <stdio.h>

int main()
{
	float metro_sec, quilo_hora;

	printf("Insira a velocidade em m/s \n");
	scanf("%f", &metro_sec);

	quilo_hora = metro_sec * 3.6;
	printf("%.2f \n", quilo_hora);

	return 0;
}
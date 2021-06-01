#include <stdio.h>
#include <stdlib.h>

int main()
{

	unsigned char a = 5, b = 9;

	printf("a = %d, b = %d \n\n", a, b);

	/* Bitwise AND */
	printf("a & b = %d \n", a & b);

	/* Bitwise OR */
	printf("a | b = %d \n", a | b);

	/* Bitwise XOR */
	printf("a ^ b = %d \n", a ^ b);

	/* Bitwise NOT */
	printf("  ~ a = %d \n", a = ~a);

	/* Bitwise Left-Shift */
	printf("b << 1 = %d \n", b << 1);

	/* Bitwise Right-Shift */
	printf("b >> 2 = %d \n", b >> 2);

	return 0;
}
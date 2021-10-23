#include <stdio.h>
#include <stdlib.h>

int main()
{

	unsigned char a = 5, b = 9;

	printf("a = %d, b = %d \n\n", a, b);
	// 00000101
	// 00001001

	/* Bitwise AND */
	printf("a & b = %d \n", a & b);
	// 00000001

	/* Bitwise OR */
	printf("a | b = %d \n", a | b);
	// 00001101

	/* Bitwise XOR */
	printf("a ^ b = %d \n", a ^ b);
	// 00001100

	/* Bitwise NOT */
	printf("  ~ a = %d \n", a = ~a);
	// 11111010

	/* Bitwise Left-Shift */
	printf("b << 1 = %d \n", b << 1);
	// 00010010

	/* Bitwise Right-Shift */
	printf("b >> 2 = %d \n", b >> 2);
	// 00000010

	return 0;
}

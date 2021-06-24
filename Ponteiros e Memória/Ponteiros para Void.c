#include <stdio.h>
#include <stdlib.h>


int main()
{
	int integer = 5;
	char character = 'A';
	void *voidPointer = NULL; // void pointer initialized pointing to NULL

	voidPointer = &integer;
	printf("Void Pointer to integer: %d \n", *(int *)voidPointer); // type cast
	voidPointer = &character;
	printf("Void Pointer to character: %c \n", *(char *)voidPointer);
	voidPointer = (void *)NULL;

	return 0;
}


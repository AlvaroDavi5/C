#include <stdio.h>
#include <stdlib.h>


struct aboutPeople {
	int birthDay;
	char *birthMonth[15];
	int birthYear;
};
typedef struct aboutPeople aboutMe;

int main()
{
	float pi = 3.141592;
	float *pi_pointer = NULL; // pointer declared (pointer-to-float)
	int array[] = {4, 5, 8, 9}, *ptr1 = NULL, *ptr2 = NULL;
	aboutMe *alvaro = NULL;

	alvaro = malloc(sizeof(aboutMe));
	alvaro->birthDay = 10; // access attribute from struct referenced by a pointer, alvaro.birthDay
	*alvaro->birthMonth = "June";
	alvaro->birthYear = 2002;
	printf("Álvaro birthay: %s %d, %d \n \n", *alvaro->birthMonth, alvaro->birthDay, alvaro->birthYear);
	free(alvaro);

	pi_pointer = &pi; // atribuited reference to pi variable adress

	printf("Pi memory adress: %p \n", pi_pointer); // reference to adress and pass it
	printf("Pi value: %f \n", *pi_pointer); // derreference to adress and pass the value, & and * make refference/derreference alternating under value and adress
	printf("\n");
	printf("Someone value: %f \n", *(pi_pointer + 1)); // increment to access the next adress value
	printf("Someone memory adress: %p \n", (pi_pointer - 1)); // decrement to access the next adress
	printf("\n");

	ptr1 = array+2;
	ptr2 = array+3; // atribute another pointer value
	printf("Difference of array positions: %ld \n", (ptr1 - ptr2));
	printf("\n");


	if (pi_pointer == (pi_pointer + 1)) // pointers comparision
	{
		printf("Pointers are equal!\n");
	}
	else
	{
		printf("Different pointers!\n");
		if (pi_pointer > pi_pointer+1)
			printf("'pi_pointer' greater than 'pi_pointer+1'.\n");
		else
			printf("'pi_pointer+1' greater than 'pi_pointer'.\n");
	}
	printf("\n");


	int n = 0, *p = NULL; // integer and pointer to a integer
	const int *pci = NULL; // pointer to a constant int
	int * const cpi = NULL; // constant pointer to a int
	const int * const cpci = NULL; // constant pointer to a constant int
	const int * const *pcpci = NULL; // pointer to a constant pointer to a constant int


	/*
	int intPi = pi;
	pi_pointer = (int *)pi_pointer; // cast pointer-to-float → pointer-to-int, we can't make it
	pi_pointer = &intPi;
	printf("Pi value now is: %i \n", *pi_pointer);
	*/


	char *my_books[] =
	{
		"Lorien Legacies",
		"The Lord of the Rings",
		"Ready Player One",
		"Dom Quixote de La Mancha",
		"The Da Vinci Code",
		"His Dark Materials"
	}; // string array with pointers, pointer-to-char array
	printf("%s \n", my_books[3]);


	return 0;
}

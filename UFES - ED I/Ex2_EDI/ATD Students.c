/*

 ALUNO: Alvaro Davi S. Alves (2020101874)

 DISCIPLINA: Estrutura de Dados I
 PROF: Patricia D. costa

 CURSO: Engenharia da Computacao
 Universidade Federal do Espirito Santo (UFES)

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// macros and constants
#define TRUE 1
#define FALSE 0
#define ARR_SIZE 46


// data structures
typedef struct
{
	char *name;
	int registration;
	float test1;
	float test2;
	float test3;
}
Student;


// functions prototypes
float studentMean(Student *student);
float classMean(Student **class, int amount);
void printApproved(Student **class, int amount);
void registerClass(Student **class, int amount);
void freeClass(Student **class, int amount);


int main()
{
	int amountStudents = 0;

	printf("Type the students amount: ");
	scanf("%i", &amountStudents);

	Student **myClass = (Student **) malloc(amountStudents * sizeof(Student *));
	registerClass(myClass, amountStudents);

	printApproved(myClass, amountStudents);
	printf("Class Mean: %.2f \n", classMean(myClass, amountStudents));

	freeClass(myClass, amountStudents);

	return 0;
}


float studentMean(Student *student)
{
	float mean = (student->test1 + student->test2 + student->test3) / 3.0;

	return mean;
}

float classMean(Student **class, int amount)
{
	float classMean = 0.00;

	for (int i = 0; i < amount; i++)
		classMean += studentMean(*(class + i));

	return classMean / ((float) amount);
}

void printApproved(Student **class, int amount)
{
	printf("Approved: \n");
	for (int i = 0; i < amount; i++)
		if (studentMean(*(class + i)) >= 5.0)
			printf("%s\n", (*(class + i))->name);
}

void registerClass(Student **class, int amount)
{
	char name[ARR_SIZE] = "";
	int registration = 000;
	float test1 = 0.00, test2 = 0.00, test3 = 0.00;

	for (int i = 0; i < amount; i++)
	{
		printf("----------------------\n");
		*(class + i) = (Student *) malloc(sizeof(Student));

		printf("Type the student name: ");
		scanf("\n %[^\n]", name);
		printf("Type the student registration: ");
		scanf("%i", &registration);
		printf("Type the student test 1 note: ");
		scanf("%f", &test1);
		printf("Type the student test 2 note: ");
		scanf("%f", &test2);
		printf("Type the student test 3 note: ");
		scanf("%f", &test3);

		(*(class + i))->name = strdup(name);
		//(*(class + i))->name = (char *) malloc(strlen(name) * sizeof(char));
		(*(class + i))->registration = registration;
		(*(class + i))->test1 = test1;
		(*(class + i))->test2 = test2;
		(*(class + i))->test3 = test3;
	}

	printf("\n");
}

void freeClass(Student **class, int amount)
{
	if (class != NULL)
	{
		for (int i = 0; i < amount; i++)
		{
			if (*(class + i) != NULL)
			{
				if ((*(class + i))->name != NULL)
				{
					free((*(class + i))->name);
					((*(class + i))->name) = NULL;
				}

				free(*(class + i));
				*(class + i) = NULL;
			}
		}

		free(class);
		class = NULL;
	}
}


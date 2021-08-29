#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"


struct student
{
	int regist;
	char *name;
	float note;
};


Student * createStudent(int regist, char *name, float note)
{
	Student *student = (Student *) malloc(sizeof(Student));

	student->regist = regist;
	student->name = strdup(name);
	student->note = note;

	return student;
}

void printStudent(Student *student)
{
	printf("Regist: %d, Name: %s, Note: %.2f \n", returnRegisterStudent(student), returnNameStudent(student), returnNoteStudent(student));
}

int returnRegisterStudent(Student *student)
{
	return student->regist;
}

char * returnNameStudent(Student *student)
{
	return student->name;
}

float returnNoteStudent(Student *student)
{
	return student->note;
}

void freeStudent(Student *student)
{
	free(student->name);
	free(student);
}

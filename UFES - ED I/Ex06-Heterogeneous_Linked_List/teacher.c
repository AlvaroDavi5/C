#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teacher.h"


struct teacher
{
	int regist;
	char *name;
	float wage;
};


Teacher * initTeacher(int regist, char *name, float wage)
{
	Teacher *teacher = (Teacher *) malloc(sizeof(Teacher));

	teacher->regist = regist;
	teacher->name = strdup(name);
	teacher->wage = wage;

	return teacher;
}

void printTeacher(Teacher *teacher)
{
	printf("Regist: %d, Name: %s, Wage: %.2f \n", returnRegisterTeacher(teacher), returnNameTeacher(teacher), returnWageTeacher(teacher));
}

int returnRegisterTeacher(Teacher *teacher)
{
	return teacher->regist;
}

char * returnNameTeacher(Teacher *teacher)
{
	return teacher->name;
}

float returnWageTeacher(Teacher *teacher)
{
	return teacher->wage;
}

void destroyTeacher(Teacher *teacher)
{
	free(teacher->name);
	free(teacher);
}


#ifndef _LIST_H

	#define _LIST_H

	#include "student.h"
	#include "teacher.h"

	typedef struct node Node;
	typedef struct list HetList;

	HetList * initList(void);
	void insStudent(HetList *list, Student *aluno);
	void insTeacher(HetList *list, Teacher *teacher);
	void printList(HetList *list);
	float barbecueValue(HetList *list);
	void destroyList(HetList *list);

#endif


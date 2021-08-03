#include <stdio.h>
#include <stdlib.h>
#include "list.h"


#define STUD 0
#define TEACH 1


struct node
{
	int type;
	void *item; // void pointer
	Node *next;
};

struct list
{
	Node *head;
	Node *current;
	Node *tail;
};


HetList * initList(void)
{
	HetList *list = (HetList *) malloc(sizeof(HetList));

	list->head = NULL;
	list->current = NULL;
	list->tail = NULL;

	return list;
}

void insStudent(HetList *list, Student *student)
{
	Node *node = (Node *) malloc(sizeof(Node));

	node->type = STUD;
	node->item = student;

	if (list->head != NULL)
	{
		node->next = list->head;
		list->head = node;
	}
	else
	{
		node->next = NULL;
		list->head = node;
		list->tail = node;
	}
}

void insTeacher(HetList *list, Teacher *teacher)
{
	Node *node = (Node *) malloc(sizeof(Node));

	node->type = TEACH;
	node->item = teacher;

	if (list->head != NULL)
	{
		node->next = list->head;
		list->head = node;
	}
	else
	{
		node->next = NULL;
		list->head = node;
		list->tail = node;
	}
}

void printList(HetList *list)
{
	Node *index = NULL;

	for (index = list->head; index != NULL; index = (index)->next)
	{
		if (index->type == STUD)
		{
			printf("STUDENT: ");
			printStudent((Student *) index->item); // type cast (changing void pointer)
		}
		if (index->type == TEACH)
		{
			printf("TEACHER: ");
			printTeacher((Teacher *) index->item);
		}
	}
}

float barbecueValue(HetList *list)
{
	float value = 0.00;
	Node *index = list->head;

	while (index != NULL)
	{
		if (index->type == STUD)
			value += 30.0;

		if (index->type == TEACH)
			value += 0.02*returnWageTeacher((Teacher *) index->item);

		index = index->next;
	}
}

void destroyList(HetList *list)
{
	list->current = list->head;
	Node *i = NULL;

	while (list->current != NULL)
	{
		i = (list->current)->next;
		free(list->current);
		list->current = i;
	}

	free(list);
}


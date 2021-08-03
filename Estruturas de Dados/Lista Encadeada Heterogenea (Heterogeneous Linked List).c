#include <stdio.h>
#include <stdlib.h>


#define REC 1
#define TRI 2
#define CIR 3
float pi = 3.141529;


typedef struct linear_shape Rectangle;
typedef struct linear_shape Triangle;
typedef struct circular_shape Circle;
struct linear_shape
{
	float height;
	float base;
	float area;
};
struct circular_shape
{
	float ray;
	float area;
};

typedef struct node Node;
struct node
{
	int type;
	void *item; // void pointer
	Node *next;
};

typedef struct list HetList;
struct list
{
	Node *head;
	Node *current;
	Node *tail;
};


HetList * initList(void);
void insShapeC(HetList *list, Circle *shape);
void insShapeRT(HetList *list, Rectangle *shape, int type);
void printList(HetList *list);
void destroyList(HetList *list);

Circle * initShapeC(float r);
Rectangle * initShapeRT(float h, float b);
void printShapeC(Circle *shape);
void printShapeRT(Rectangle *shape);
float returnRay(Circle *shape);
float returnBase(Rectangle *shape);
float returnHeight(Rectangle *shape);


int main()
{
	Circle *c1 = initShapeC(5);
	Circle *c2 = initShapeC(7);
	Rectangle *r1 = initShapeRT(4, 6);
	Triangle *t1 = initShapeRT(4, 6);

	HetList *my_list = initList();

	insShapeC(my_list, c1);
	insShapeC(my_list, c2);
	insShapeRT(my_list, r1, 1);
	insShapeRT(my_list, t1, 2);

	printList(my_list);

	destroyList(my_list);
	free(c1);
	free(c2);
	free(r1);
	free(t1);

	return 0;
}


HetList * initList(void)
{
	HetList *list = (HetList *) malloc(sizeof(HetList));

	list->head = NULL;
	list->current = NULL;
	list->tail = NULL;

	return list;
}

void insShapeC(HetList *list, Circle *shape)
{
	Node *node = (Node *) malloc(sizeof(Node));

	node->type = CIR;
	node->item = shape;

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

void insShapeRT(HetList *list, Rectangle *shape, int type)
{
	Node *node = (Node *) malloc(sizeof(Node));

	if (type == 2)
		node->type = TRI;
	else
		node->type = REC;

	node->item = shape;

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
		if (index->type == CIR)
		{
			printf("Circle: ");

			if (((Circle *) index->item)->area == 0.00)
				((Circle *) index->item)->area = pi * returnRay((Circle *) index->item)*returnRay((Circle *) index->item);

			printShapeC((Circle *) index->item); // type cast (changing void pointer)
		}
		if (index->type == REC)
		{
			printf("Rectangle: ");

			if (((Rectangle *) index->item)->area == 0.00)
				((Rectangle *) index->item)->area = returnBase((Rectangle *) index->item) * returnHeight((Rectangle *) index->item);

			printShapeRT((Rectangle *) index->item);
		}
		if (index->type == TRI)
		{
			printf("Triangle: ");

			if (((Triangle *) index->item)->area == 0.00)
				((Triangle *) index->item)->area = (returnBase((Triangle *) index->item) * returnHeight((Triangle *) index->item)) / 2;

			printShapeRT((Triangle *) index->item);
		}
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

Circle * initShapeC(float r)
{
	Circle *shape = (Circle *) malloc(sizeof(Circle));

	shape->ray = r;
	shape->area = 0.00;

	return shape;
}

Rectangle * initShapeRT(float h, float b)
{
	Rectangle *shape = (Rectangle *) malloc(sizeof(Rectangle));

	shape->height = h;
	shape->base = b;
	shape->area = 0.00;

	return shape;
}

void printShapeC(Circle *shape)
{
	printf("r = %f, Area = %f \n", returnRay(shape), shape->area);
}

void printShapeRT(Rectangle *shape)
{
	printf("h = %f, b = %f, Area = %f \n", returnHeight(shape), returnBase(shape), shape->area);
}

float returnRay(Circle *shape)
{
	return shape->ray;
}

float returnBase(Rectangle *shape)
{
	return shape->base;
}

float returnHeight(Rectangle *shape)
{
	return shape->height;
}


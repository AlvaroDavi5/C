#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main()
{
	Student *rose = initStudent(2001, "Rose Tyler", 7);
	Student *mick = initStudent(2010, "Mickey Smith", 6);
	Student *martha = initStudent(2002, "Martha Jones", 9);
	Student *boe = initStudent(4010, "Jack Harkness", 10);

	Teacher *chris = initTeacher(1009, "Christopher Eccleston", 9000);
	Teacher *david = initTeacher(1010, "David Tennant", 10000);

	HetList *my_list = initList();

	insStudent(my_list, boe);
	insStudent(my_list, martha);
	insStudent(my_list, rose);
	insStudent(my_list, mick);
	insTeacher(my_list, chris);
	insTeacher(my_list, david);

	printf("Total amount raised for the barbecue: US$ %.2f \n", barbecueValue(my_list));
	printf("List of who goes: \n");
	printList(my_list);

	destroyList(my_list);
	destroyTeacher(chris);
	destroyTeacher(david);
	destroyStudent(boe);
	destroyStudent(mick);
	destroyStudent(martha);
	destroyStudent(rose);

	return 0;
}


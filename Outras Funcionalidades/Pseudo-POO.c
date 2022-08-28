/*

	no lugar de classes com atributos e metodos teremos structs com membros e ponteiros para funcoes, no lugar de getters e setters publicos e privados teremos simples funçoes com acesso livre aos atributos/membros e metodos/funcoes
		~Alvaro Davi

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define Class struct

Class Person
{
	char name[10];
	int age;
	int height;
	void(*show)(Class Person *);
}; // pseudo class (struct)
//typedef person* Person;


int getAge(Class Person *person)
{
	return person->age; // getter
}

void setAge(Class Person *person, int value)
{
	person->age = value; // setter
}

void setMethod(Class Person *person, void(*pointer)(Class Person *))
{
	person->show = pointer; // pseudo-polimorphism
}


void personPrint(Class Person *person)
{
	printf("Name: %s \nAge: %d \nHeight: %d \n", person->name, getAge(person), person->height);
}

void ImprimePessoa(Class Person *person)
{
	printf("Nome: %s \nIdade: %d \nAltura: %d \n", person->name, person->age, person->height);
}


Class Person * newPerson(char name[], int age, int height)
{
	Class Person *person = (Class Person *) malloc(sizeof(Class Person)); // pseudo-constructor

	strcpy(person->name, name); // pseudo-attributes (struct members)
	person->age = age;
	person->height = height;
	person->show = &personPrint; // pseudo-methods (function pointers)

	return person;
}



int main()
{
	Class Person *self = newPerson("Antonio", 18, 170); // pseudo-instantion
	self->show(self); // pseudo self-reference

	setAge(self, 19); // pseudo-encapsulation
	setMethod(self, &ImprimePessoa); // pseudo overriding/overloading

	printf("\n");
	self->show(self);

	return 0;
}

/*

	no lugar de classes com atributos e metodos teremos structs com membros e ponteiros para funcoes, no lugar de getters e setters publicos e privados teremos simples funçoes com acesso livre aos atributos/membros e metodos/funcoes
		~Alvaro Davi

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define Class struct

//typedef Class person Person;
Class Person
{
	char name[10];
	int age;
	int height;
	void(*show)(Class Person *);
};


int getAge(Class Person *person)
{
	return person->age;
}

void setAge(Class Person *person, int value)
{
	person->age = value;
}

void setMethod(Class Person *person, void(*pointer)(Class Person *))
{
	person->show = pointer;
}


void personPrint(Class Person *person)
{
	printf("Name: %s \nAge: %d \nHeight: %d \n", person->name, getAge(person), person->height); // getter usado para atributo/membro
}

void ImprimePessoa(Class Person *person)
{
	printf("Nome: %s \nIdade: %d \nAltura: %d \n", person->name, person->age, person->height);
}


Class Person * newPerson(char name[], int age, int height)
{
	Class Person *person = (Class Person *) malloc(sizeof(Class Person));

	strcpy(person->name, name); // atributos (membros)
	person->age = age;
	person->height = height;
	person->show = &personPrint; // metodo (ponteiro para funcao)

	return person;
}



int main()
{
	Class Person *self = newPerson("Antonio", 18, 170); // isso seria um objeto, a instancia de uma classe 'Person'
	self->show(self); // isso seria o metodo 'show' com 'self' ou 'this'

	setAge(self, 19); // setter usado para atributo/membro
	setMethod(self, &ImprimePessoa); // setter usado para metodo/funcao

	printf("\n");
	self->show(self);

	return 0;
}

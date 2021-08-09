/*
 Student/Register: Alvaro Davi S. Alves - 2020101874
 Subject/Teacher: Estruturas de Dados I - Patricia D. Costa
 University/Course: UFES - Engenharia de Computação
*/

#ifndef _DOUBLE_STACK
	#define _DOUBLE_STACK

	typedef struct stack Stack; // Stack is a LIFO data structure

	Stack * createStack(unsigned int capacity);
	void freeStack(Stack *stack);
	void push(Stack *stack, int item, int top);
	int pop(Stack *stack, int top);
	int peek(Stack *stack, int top);
	int isFull(Stack *stack);
	int isEmpty(Stack *stack);

#endif

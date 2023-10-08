#include <stdio.h>
#include <stdlib.h>

#define Item int

#define TB_SIZE 31

void initHashTable(int *table, unsigned int size);
void insert(int *table, Item value);
int search(int *table, Item value);
void print(int *table, int size);

int main()
{
	int hash_table[TB_SIZE], n = 0;
	initHashTable(hash_table, TB_SIZE);

	while (n >= 0)
	{
		printf("Type a number N between 0 and %d to insert and N < 0 to exit: ", TB_SIZE);
		scanf("%d", &n);
		insert(hash_table, n);
	}

	int s_res = search(hash_table, 15);
	printf("Search Result: %d \n", s_res);

	print(hash_table, TB_SIZE);

	return 0;
}

void initHashTable(int *table, unsigned int size)
{
	for (int i = 0; i < size; i++)
		table[i] = 0;
}

int hash(int key, unsigned int size)
{
	return (key % size);
}

void insert(int *table, Item value)
{
	int id = hash(value, TB_SIZE);

	while (table[id] != 0)
	{
		id = hash(id + 1, TB_SIZE);
	}
	table[id] = value;
}

int search(int *table, Item value)
{
	int id = hash(value, TB_SIZE);
	while (table[id] != 0)
	{
		if (table[id] == value)
			return table[id];
		else
			id = hash(id + 1, TB_SIZE);
	}
	return 0;
}

void print(int *table, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d = %d\n", i, table[i]);
	}
}

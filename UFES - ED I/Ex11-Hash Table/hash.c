#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./hash.h"


struct hash
{
	Word **words;
	int size;
};


static int hash(char *str, int size)
{
	int total = 0;

	for (int i = 0; str[i] != '\0'; i++)
		total += str[i];

	return (total % size);
}

Hash * initHash(int size)
{	
	Hash *h = (Hash *) malloc(sizeof(Hash));
	h->size = size;
	h->words = (Word **) malloc(size * sizeof(Word *));

	for (int i = 0; i < size; i++)
		h->words[i] = NULL;

	return h;
}

Word * access(Hash *h, char *str)
{
	Word *wrd;

	int index = hash(str, h->size);

	wrd = searchWord(h->words[index], str);

	if (wrd)
	{
		return wrd;
	}
	else
	{
		wrd = createWord(str);
		h->words[index] = insertWord(h->words[index], wrd);
		return wrd;
	}
}

int countWords(Hash *h)
{
	int sum = 0;

	for (int i = 0; i < h->size; i++)
		sum += countWordList(h->words[i]);

	return sum;
}

void printHash(Hash *h)
{
	for (int i = 0; i < h->size; i++)
	{
		printf("\nArray Position: [%d] \n", i);
		printWord(h->words[i]);
	}
}

void freeHash(Hash *h)
{
	for (int i = 0; i < h->size; i++)
		freeWordList(h->words[i]);
	free(h->words);
	free(h);
}

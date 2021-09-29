#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./word.h"


struct word
{
	char *string;
	int n;
	Word *next;
};


Word * createWord(char *str)
{
	Word *wrd = (Word *) malloc(sizeof(Word));
	wrd->string = strdup(str);
	wrd->n = 0;
	wrd->next = NULL;

	return wrd;
}

char * getWord(Word *wrd)
{
	return wrd->string;
}

void updateOccurrences(Word *wrd)
{
	wrd->n += 1;
}

int getOccurrences(Word *wrd)
{
	return wrd->n;
}

Word * searchWord(Word *wrd, char *str)
{
	Word *w;
	for (w = wrd; w != NULL; w = w->next)
	{
		if (strcmp(str, w->string) == 0)
			return w;
	}
	return NULL;
}

Word * insertWord(Word *word_list, Word *wrd)
{
	wrd->next = word_list;
	return wrd;
}

int countWordList(Word *wrd)
{
	Word *word = NULL;
	int i = 0;

	for (word = wrd; word != NULL; word = word->next)
		i++;

	return i;
}

void printWord(Word *wrd)
{
	Word *aux = NULL;

	for (aux = wrd; aux != NULL; aux = aux->next)
		printf("String: %s - Occurrences: %d \n", aux->string, aux->n);
}

void freeWordList(Word *wrd)
{
	Word *aux = wrd, *w = NULL;

	while (aux != NULL)
	{
		w = aux->next;
		free(aux->string);
		free(aux);
		aux = w;
	}
}

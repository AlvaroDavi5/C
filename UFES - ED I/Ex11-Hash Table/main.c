#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "./word.h"
#include "./hash.h"


#define NTAB 127
#define NWRD 64


static int readWord(FILE *file, char *str);


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("File not found!\n");
		return 0;
	}

	FILE* fp = fopen(argv[1], "rt");

	if (fp = NULL)
	{
		printf("Error to open file.\n");
		return 1;
	}


	Hash *hash_table = initHash(NTAB);
	char string[NWRD];

	while (readWord(fp, string))
	{
		Word *wrd = access(hash_table, string);
		updateOccurrences(wrd);
	}

	printHash(hash_table);
	
	freeHash(hash_table);
	fclose(fp);

	return 0;
}

static int readWord(FILE *file, char *str)
{
	int i = 0;
	int c;

	while ((c = fgetc(file)) != EOF)
	{
		if (isalpha(c))
			break;
	}

	if (c == EOF)
		return 0;

	else
		str[i++] = c;

	while ((i < NWRD-1) && (c = fgetc(file)) != EOF && isalpha(c))
		str[i++] = c;

	str[i] = '\0';

	return i;
}

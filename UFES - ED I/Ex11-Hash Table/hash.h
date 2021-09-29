#ifndef HASH_H

	#define HASH_H

	#include "./word.h"

	typedef struct hash Hash;

	Hash * initHash(int size);
	Word * access(Hash *h, char *str);
	int countWords(Hash *h);
	void printHash(Hash *h);
	void freeHash(Hash *h);

#endif

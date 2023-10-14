#ifndef _ITEM_H

#define _ITEM_H

#include <stdio.h>
#include <stdlib.h>

typedef int Item;

// pre-processing macros
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define swap(A, B) \
	{                \
		Item aux = A;  \
		A = B;         \
		B = aux;       \
	}

#endif

#ifndef _UTILS_H

	#define _UTILS_H

	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>

	void safeFree(void *ptr);
	bool wasAllocated(void *pointer);

#endif

#ifndef _UTILS_H

	#define _UTILS_H

	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include <time.h>

	typedef struct {
		long seconds;
		long milliseconds;
	} TimeElapsed;

	void *allocateArray(unsigned int arraySize, unsigned long byteSize);
	void safeFree(void *ptr);
	bool wasAllocated(void *pointer);
	struct timespec getTimeStart(void);
	TimeElapsed getTimeElapsed(struct timespec start);

#endif

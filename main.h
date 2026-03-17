#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

typedef struct format
{
	int zero;
	int plus;
	int minus;
	int space;
	int width;
	int per;
} format;

void finit(format *);

#endif

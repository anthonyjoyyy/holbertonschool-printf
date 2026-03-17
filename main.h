#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

typedef struct flag
{
	int zero;
	int plus;
	int minus;
	int space;
	int width;
	int per;
} flag;

void finit(flag *);
int _printf(const char *format, ...);

#endif

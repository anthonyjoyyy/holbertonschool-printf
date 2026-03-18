#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * struct flag - data type for storing flag setings
 * @zero: 1, if true, else 0
 * @plus: 1, if true, else 0
 * @minus: 1, if true, else 0
 * @space: 1, if true, else 0
 * @width: 1, if true, else 0
 * @per: 1, if true, else 0
 */
typedef struct flag
{
	int zero;
	int plus;
	int minus;
	int space;
	int width;
	int per;
} flag;

void printchar(char);
void finit(flag *);
int _printf(const char *format, ...);
int dflag(flag *, const char *, int);

#endif

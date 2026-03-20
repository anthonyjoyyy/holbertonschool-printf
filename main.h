#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
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

int specifier(flag *, va_list, char);
int prntc(flag *, char);
int prnts(flag *, char *);
int prntchar(char);
void finit(flag *);
void sinit(char *, int);
char *lstrgen(char *, int);
int fstrlen(flag *flager, char *str);
int _printf(const char *format, ...);
int dflag(flag *, const char *, int);
int dwidth(flag *, const char *, int);

#endif

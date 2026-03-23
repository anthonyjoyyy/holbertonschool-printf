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
 * @flaged: posision where % was first found
 */
typedef struct flag
{
	int zero;
	int plus;
	int minus;
	int space;
	int width;
	int per;
	int flaged;
} flag;

int specifier(flag *, va_list, const char *, int);
int prntc(flag *, char);
int prnts(flag *, char *);
int prntd(flag *, int);
int prntund(flag *, const char *, int);
int prntchar(char);
void finit(flag *);
void sinit(char *, int, char);
char *lstrgen(char *, int);
char *inttostr(int, int);
void revstr(char *, int, int);
int fstrlen(flag *flager, char *str);
int _printf(const char *format, ...);
int dflag(flag *, const char *, int);
int dwidth(flag *, const char *, int, va_list);
int dper(flag *, const char *, int);

#endif

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
/**
 * struct formats - stores a format and corisponding function
 * @spec: stores format repisentitive
 * @f: stores matching function
 */
typedef struct formats
{
	char spec;
	int (*f)(flag *, va_list);
} formats;

void finit(flag *);
void sinit(char *, int, char);

int dflag(flag *, const char *, int);
int dwidth(flag *, const char *, int, va_list);
int dper(flag *, const char *, int);

int fstrlen(flag *flager, char *str);
char *lstrgen(char *, int);
char *inttostr(int, int);
void revstr(char *, int, int);

int specifier(flag *, va_list, const char *, int);
int prntc(flag *, va_list);
int prnts(flag *, va_list);
int prntd(flag *, va_list);
int prntund(flag *, const char *, int);
int prntchar(char);

int _printf(const char *format, ...);


#endif

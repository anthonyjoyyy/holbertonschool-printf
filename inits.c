#include "main.h"

/**
 * finit - initalize a variable of flag type
 * @f: variable to initialize
 */
void finit(flag *f)
{
	if (f == NULL)
		return;
	f->zero = 0;
	f->plus = 0;
	f->minus = 0;
	f->space = 0;
	f->width = 0;
	f->per = 0;
}
/**
 * sinit - inialize a string to ' ', and terminate
 * @str: pointer to string
 * length of string not including NULL byte
 */
void sinit(char *str, int n)
{
	int i = 0;
	
	str[n] = '\0';
	while(i < n)
	{
		str[i] = ' ';
		i++;
	}
}

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
	f->per = -1;
	f->flaged = -1;
}
/**
 * sinit - inialize a string to ' ', and terminate
 * @str: pointer to string
 * @n: length of string not including NULL byte
 */
void sinit(char *str, int n)
{
	int i = 0;

	str[n] = '\0';
	while (i < n)
	{
		str[i++] = ' ';
	}
}

/**
 * lstrgen - generate a string from main string and string length
 * @str: main string to set from
 * @stln: string length
 * Return: pointer to generated string
 */
char *lstrgen(char *str, int stln)
{
	char *lstr;
	int i;

	lstr = malloc(stln * sizeof(*lstr));
	if (!lstr)
		return (0);
	sinit(lstr, stln);
	for (i = 0; str[i] && i < stln; i++)
		lstr[i] = str[i];
	return (lstr);
}

/**
 * fstrlen - get string length with persion
 * @flager: pointer to flag struct containing persion
 * @str: main string for length
 * Return: length of string modified by persion
 */
int fstrlen(flag *flager, char *str)
{
	int stln = 0;

	for (; str[stln]; stln++)
	if (flager->per > -1 && flager->per < stln)
		stln = flager->per;
	return (stln);
}

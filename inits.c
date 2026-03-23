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
 * @fill: character to fill string with
 */
void sinit(char *str, int n, char fill)
{
	int i = 0;

	str[n] = '\0';
	while (i < n)
	{
		str[i++] = fill;
	}
}

/**
 * lstrgen - generate a string from main string and string length
 * @str: main string to set from
 * @len: string length
 * Return: pointer to generated string
 */
char *lstrgen(char *str, int len)
{
	char *lstr;
	int i;

	lstr = malloc((len + 1) * sizeof(*lstr));
	if (!lstr)
		return (0);
	sinit(lstr, len, ' ');
	for (i = 0; str[i] && i < len; i++)
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
	int len = 0;

	for (; str[len]; )
		len++;
	if (flager->per > -1 && flager->per < len)
		len = flager->per;
	return (len);
}

#include "main.h"

/**
 * prntchar - print a single char
 * @a: char to print
 */
void prntchar(char a)
{
	write(1, &a, 1);
}

/**
 * prntc - print a character with formating
 * @flager: pointer to flag type variable
 * @c: character to print
 */
void prntc(flag *flager, char c)
{
	char *a;
	int i = 0;
	int n;

	if (flager == NULL)
		return;

	if (flager->width)
		n = flager->width;
	else
		n = 1;

	a = malloc((n + 1) * sizeof(*a));
	if (!a)
		return;

	a[n] = '\0';
	while (i < n)
	{
		a[i++] = ' ';
	}

	if (flager->minus)
		a[0] = c;
	else
		a[n-1] = c;

	write(1, a, n);
	free(a);
}

/**
 */
void prnts(flag *flager, char *str)
{
	int stln = 0;
	int wdt = 0;
	char *str2;
	int wn;
	int i;
	int x;

	if (flager == NULL)
		return;
	
	while (str[stln])
	{
		stln++;
	}

	if (flager->width)
		wdt = flager->width;

	if (wdt > stln)
	{
		wn = wdt;

		str2 = malloc(wn * sizeof(*str2));
		if (!str2)
			return;

		i = 0;
		while (i < wn)
		{
			str2[i++] = ' ';
		}
		if (flager->minus)
		{
			i = 0;
			while (str[i])
			{
				str2[i] = str[i];
				i++;
			}
		}
		else
		{
			x = stln;
			while (x >= 0)
			{
				str2[i--] = str[x--];
			}
		}
	}
	else
	{
		wn = stln;
		str2 = str;
	}

	write(1, str2, wn);
}

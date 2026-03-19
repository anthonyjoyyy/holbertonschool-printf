#include "main.h"

/**
 * prntchar - print a single char
 * @a: char to print
 */
int prntchar(char a)
{
	write(1, &a, 1);
	return (1);
}

/**
 * prntc - print a character with formating
 * @flager: pointer to flag type variable
 * @c: character to print
 */
int prntc(flag *flager, char c)
{
	char *a;
	int n;

	if (flager == NULL)
		return (0);

	if (flager->width)
		n = flager->width;
	else
		n = 1;

	a = malloc((n + 1) * sizeof(*a));
	if (!a)
		return (0);

	sinit(a, n);

	if (flager->minus)
		a[0] = c;
	else
		a[n - 1] = c;

	write(1, a, n);
	free(a);
	return (n);
}

/**
 * prnts - prints a string formated with flags and width
 * @flager: pointer to flag stuct containing flag and width settings
 * @str: string to print
 */
int prnts(flag *flager, char *str)
{
	char *lstr;
	int stln = 0;
	int wdt = flager->width;
	int p = flager->per;
	int i;
	int x;

	if (flager == NULL)
		return (0);

	while (str[stln])
	{
		stln++;
	}
	if (p > -1 && p < stln)
		stln = p;
	
	lstr = malloc(stln * sizeof(*lstr));
	if (!lstr)
		return (0);

	sinit(lstr, stln);
	i = 0;
	while (str[i] && i < stln)
	{
		lstr[i] = str[i];
		i++;
	}

	if (wdt > stln)
	{
		char *str2;
		int wn = wdt;

		str2 = malloc(wn * sizeof(*str2));
		if (!str2)
		{
			free(lstr);
			return (0);
		}

		sinit(str2, wn);
		if (flager->minus)
		{
			i = 0;
			while (lstr[i])
			{
				str2[i] = lstr[i];
				i++;
			}
		}
		else
		{
			x = stln;
			i = wn;
			while (x >= 0)
			{
				str2[i--] = lstr[x--];
			}
		}
		write(1, str2, wn);
		free(str2);
		free(lstr);
		return (wn);
	}
	else
	{
		write(1, lstr, stln);
		free(lstr);
		return (stln);
	}
}

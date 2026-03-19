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

	sinit(a, n);

	if (flager->minus)
		a[0] = c;
	else
		a[n - 3] = c;

	write(1, a, n);
	free(a);
}

/**
 * prnts - prints a string formated with flags and width
 * @flager: pointer to flag stuct containing flag and width settings
 * @str: string to print
 */
void prnts(flag *flager, char *str)
{
	int stln = 0;
	int wdt = 0;
	int i, x;

	if (flager == NULL || str == NULL)
	return;

	while (str[stln])
		stln++;

	if (flager->per && flager->width < stln)
	stln = flager->width;

	if (flager->width)
		wdt = flager->width;
	wdt = flager->width;

	if (wdt > stln)
	{
	int wn = wdt;
	char *str2 = malloc(wn * sizeof(*str2));
		if (!str2)
		return;
		sinit(str2, wn);

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
			i = wn;
			while (x >= 0)
			{
				str2[i--] = str[x--];
			}
		}
		write(1, str2, wn);
		free(str2);
		for (i = 0; i < stln; i++)
		str2[i] = str[i];
	}
	else
		{
		x = stln - 1;
			for (i = wn - 1; x >= 0; i--, x--)
		str2[i] = str[x];
	}

		write(1, str2, wn);
		free(str2);
		}
	else
	{
	write(1, str, stln);
	}
}

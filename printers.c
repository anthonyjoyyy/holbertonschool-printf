#include "main.h"

/**
 * prntchar - print a single char
 * @a: char to print
 * Return: number of characters printed
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
 * Return: number of characters printed
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
 * Return: number of characters printed
 */
int prnts(flag *flager, char *str)
{
	char *lstr;
	int stln, i, x;

	if (flager == NULL)
		return (0);
	if (str == NULL)
	{
		write(1, &"(null)", 6);
		return (6);
	}
	stln = fstrlen(flager, str);
	lstr = lstrgen(str, stln);
	if (flager->width > stln)
	{
		int wn = flager->width;
		char *str2 = malloc(wn * sizeof(*str2));

		if (!str2)
		{
			free(lstr);
			return (0);
		}
		sinit(str2, wn);
		if (flager->minus)
		{
			for (i = 0; lstr[i]; i++)
				str2[i] = lstr[i];
		}
		else
		{
			x = stln;
			for (i = wn; x >= 0;)
				str2[i--] = lstr[x--];
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

/**
 * prntund - handle printing when an undifined specifier is passed
 */
int prntund(flag *flager, const char *format, int pos)
{
	int cc = 0;
	int len;
	int fpos;
	char *str;

	if (flager == NULL)
		return (0);

	fpos = flager->flaged;
	len = (pos - fpos) + 1;
	str = malloc((len + 1) * sizeof(*str));
	sinit(str, len);

	while (fpos <= pos)
	{
		str[cc++] = format[fpos++];
	}
	write(1, str, cc);
	free(str);

	return (cc);
}

#include "main.h"

/**
 * prntchar - print a single char
 * @a: char to print
 * Return: number of characters printed
 */
int prntchar(char a)
{
	return (write(1, &a, 1));
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
	sinit(a, n, ' ');

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
		return (write(1, &"(null)", 6));
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
		sinit(str2, wn, ' ');
		if (flager->minus)
			for (i = 0; lstr[i]; i++)
				str2[i] = lstr[i];
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
 * @flager: flager struct, holds posision '%' was first detected
 * @format: main string to print from
 * @pos: curent posion in format
 * Return: number of characters printed
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
	sinit(str, len, ' ');

	while (fpos <= pos)
	{
		str[cc++] = format[fpos++];
	}
	write(1, str, cc);
	free(str);
	return (cc);
}

/**
 * prntd -
 * @flager:
 * @dig:
 * Return:
 */
int prntd(flag *flager, int dig)
{
	char *str;
	char *tmpstr;
	int dig2 = dig;
	int len, i, x, z;

	for (len = 0; dig2; len++)
		dig2 = dig2 / 10;
	if (dig < 0)
		len++;
	if (flager == NULL)
		return (0);
	str = inttostr(dig, len);
	if (flager->per > len)
	{
		tmpstr = malloc((flager->per + 1) * sizeof(*str));
		tmpstr[len] = '\0';
		for (z = 0; z < (flager->per - len); z++)
			tmpstr[z] = '0';
		for (z = 0; z < len; z++)
			tmpstr[z + (flager->per - len)] = str[z];
		len = flager->per;
		str = tmpstr;
	}
	if (flager->space)
	{
		len++;
		tmpstr = malloc((len + 1) * sizeof(*str));
		tmpstr[0] = ' ';
		for (z = 1; z < len; z++)
			tmpstr[z] = str[z - 1];
		str = tmpstr;
	}
	if (flager->plus)
	{
		len++;
		tmpstr = malloc((len + 1) * sizeof(*str));
		tmpstr[0] = '+';
		for (z = 1; z < len; z++)
			tmpstr[z] = str[z - 1];
		str = tmpstr;
	}
	if (flager->width > len)
	{
		int wn = flager->width;
		char *str2 = malloc(wn * sizeof(*str2));

		if (!str2)
		{
			free(str);
			return (0);
		}
		if (flager->zero)
			sinit(str2, wn, '0');
		else
			sinit(str2, wn, ' ');
		if (flager->minus)
			for (i = 0; str[i]; i++)
				str2[i] = str[i];
		else
		{
			x = len;
			for (i = wn; x >= 0;)
				str2[i--] = str[x--];
		}
		write(1, str2, wn);
		free(str2);
		free(str);
		return (wn);
	}
	return (write(1, str, len));
}

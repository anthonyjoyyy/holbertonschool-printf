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
 * @varg: va_list containing character to print
 * Return: number of characters printed
 */
int prntc(flag *flager, va_list varg)
{
	char c = va_arg(varg, int);
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
 * @varg: va_list containing string to print
 * Return: number of characters printed
 */
int prnts(flag *flager, va_list varg)
{
	char *str = va_arg(varg, char *);
	int len, i, n;

	if (flager == NULL)
		return (0);
	if (str == NULL)
		return (write(1, &"(null)", 6));
	len = fstrlen(flager, str);
	str = lstrgen(str, len);
	if (flager->width > len)
	{
		int wn = flager->width;
		char *str2 = malloc((wn + 1) * sizeof(*str2));

		if (!str2)
		{
			free(str);
			return (0);
		}
		sinit(str2, wn, ' ');
		if (flager->minus)
			for (i = 0; str[i]; i++)
				str2[i] = str[i];
		else
		{
			n = len;
			for (i = wn; n >= 0;)
				str2[i--] = str[n--];
		}
		write(1, str2, wn);
		free(str2);
		free(str);
		return (wn);
	}
	else
	{
		write(1, str, len);
		free(str);
		return (len);
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
 * prntd - print a signed int
 * @flager: flager stuct storing format options
 * @varg: va_list contianing digit to print
 * Return: number of characters printed
 */
int prntd(flag *flager, va_list varg)
{
	int d = va_arg(varg, int);
	int n = d;
	int len, y, x;
	char *str, *tmpstr;

	if (!d)
		len = 1;
	else
		for (len = 0; n; len++)
		n = n / 10;
	if (d < 0)
		len++;
	if (flager == NULL)
		return (0);
	str = inttostr(d, len);
	if (flager->per > len)
	{
		tmpstr = malloc((flager->per + 1) * sizeof(*str));
		tmpstr[len] = '\0';
		for (x = 0; x < (flager->per - len); x++)
			tmpstr[x] = '0';
		for (x = 0; x < len; x++)
			tmpstr[x + (flager->per - len)] = str[x];
		len = flager->per;
		free(str);
		str = tmpstr;
	}
	if (flager->space && d >= 0)
	{
		len++;
		tmpstr = malloc((len + 1) * sizeof(*str));
		tmpstr[0] = ' ';
		for (x = 1; x < len; x++)
			tmpstr[x] = str[x - 1];
		free(str);
		str = tmpstr;
	}
	if (flager->plus && d >= 0)
	{
		len++;
		tmpstr = malloc((len + 1) * sizeof(*str));
		tmpstr[0] = '+';
		for (x = 1; x < len; x++)
			tmpstr[x] = str[x - 1];
		free(str);
		str = tmpstr;
	}
	if (flager->width > len)
	{
		int wn = flager->width;
		char *str2 = malloc((wn + 1) * sizeof(*str2));

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
			for (y = 0; str[y]; y++)
				str2[y] = str[y];
		else
		{
			x = len;
			for (y = wn; x >= 0;)
			{
				if (flager->zero && x == 0)
					str2[0] = str[x--];
				else
					str2[y--] = str[x--];
			}
		}
		write(1, str2, wn);
		free(str2);
		free(str);
		return (wn);
	}
	y = write(1, str, len);
	free(str);
	return (y);
}

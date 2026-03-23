#include "main.h"

/**
 * specifier - call apopriate function for printing based on given char
 * @flager: flag struct storing formating options
 * @varg: va_list varable to print
 * @format: main string
 * @pos: pos of specifier
 * Return: number of characters printed
 */
int specifier(flag *flager, va_list varg, const char *format, int pos)
{
	formats forms[] = {
	{'c', prntc},
	{'s', prnts},
	{'d', prntd},
	{'i', prntd},
	{'\0', '\0'}
	};
	char c = format[pos];
	int i = 0;

	while (forms[i].spec)
	{
		if (forms[i].spec == c)
			return (forms[i].f(flager, varg));
		i++;
	}
	return (prntund(flager, format, pos));
}

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
	char c = format[pos];
	int cc;

	switch (c)
	{
	case 'c':
		cc = prntc(flager, va_arg(varg, int));
		return (cc);
	case 's':
		cc = prnts(flager, va_arg(varg, char *));
		return (cc);
	case 'd':
        	cc = prntd(va_arg(varg, int));
        	return (cc);
	case 'i':
        	cc = prntd(va_arg(varg, int));
        	return (cc);
	default:
		cc = prntund(flager, format, pos);
		return (cc);
	}
}

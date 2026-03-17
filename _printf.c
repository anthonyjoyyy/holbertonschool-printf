#include "main.h"

/**
 * _printf - printf clone
 *
 */
int _printf(const char *format, ...)
{
	flag flager;
	int pos = 0;
	int pc = 0;

	while (format[pos])
	{
		finit(&flager);
		if (format[pos] == '%')
		{
			pos = dflag(&flager, format, pos);
		}
		else
		{
			printchar(format[pos]);
			pos++;
		}
	}
	return (pc);
}

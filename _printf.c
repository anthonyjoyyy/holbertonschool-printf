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
			if (format[pos + 1] == '%')
			{
				printchar(format[pos++]);
			}
			else
			{
				pos = dflag(&flager, format, pos);
/**
 *	 			pos = dwidth(&flager, format, pos);
 * 				pos = dper(&flager, format, pos);
 * 				pos = specifier(&flager, format[pos++]);
 */
 			}
		}
		else
		{
			printchar(format[pos]);
			pos++;
		}
	}
	return (pc);
}

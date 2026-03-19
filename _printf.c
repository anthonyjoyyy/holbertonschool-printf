#include "main.h"

/**
 * _printf - printf clone
 * @format: string to print, with format specifers to substitue
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	flag flager;
	int pos = 0;
	int pc = 0;
	va_list varg;

	va_start(varg, format);
	while (format[pos])
	{
		finit(&flager);
		if (format[pos] == '%')
		{
			if (format[pos + 1] == '%')
			{
				prntchar(format[++pos]);
				pos++;
			}
			else
			{
				pos = dflag(&flager, format, pos);
				pos = dwidth(&flager, format, pos);
/**				pos = dper(&flager, format, pos); */
				pc += specifier(&flager, varg, format[pos++]);
			}
		}
		else
		{
			pc += prntchar(format[pos++]);
		}
	}
	va_end(varg);
	return (pc);
}

#include "main.h"

/**
 * _printf - printf clone
 * @format: string to print, with format specifers to substitue
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	flag flager;
	int pos;
	int pc = 0;
	va_list varg;

	va_start(varg, format);
	for (pos = 0; format[pos]; pos++)
	{
		if (format[pos] == '%' && format[pos + 1] == '\0')
			return (-1);
		if (format[pos] == '%' && format[pos + 1] == '%')
			pos++;
	}

	pos = 0;
	while (format[pos])
	{
		finit(&flager);
		if (format[pos] == '%')
		{
			flager.flaged = pos;
			pos++;
			if (format[pos] == '%')
			{
				pc += prntchar(format[pos]);
				pos++;
			}
			else
			{
				pos = dflag(&flager, format, pos);
				pos = dwidth(&flager, format, pos);
/**				pos = dper(&flager, format, pos); */
				pc += specifier(&flager, varg, format, pos++);
			}
		}
		else
			pc += prntchar(format[pos++]);
	}
	va_end(varg);
	return (pc);
}

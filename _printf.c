#include "main.h"

/**
 * finit - initalize a variable of flag type
 * @f: variable to initialize
 */
void finit(flag *f)
{
	if (f == NULL)
		return;
	f->zero = 0;
	f->plus = 0;
	f->minus = 0;
	f->space = 0;
	f->width = 0;
	f->per = 0;
}

/**
 * _printf - printf clone
 *
 */
int _printf(const char *format, ...)
{
	char const *a;
	int x = 0;
	int i = 0;

	while (format[x])
	{
		if (format[x] == '%')
		{
			/**code*/
		}
		else
		{
			a = &format[x];
			write(1, a, 1);
			x++;
		}
	}
	return i;
}

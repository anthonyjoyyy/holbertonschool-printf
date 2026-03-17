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
	char const *wc;
	int pos = 0; int pc = 0;

	while (format[pos])
	{
		if (format[pos] == '%')
		{
/**			int b
			pos++;
			switch (f) */
		}
		else
		{
			wc = &format[pos];
			write(1, wc, 1);
			pos++;
		}
	}
	return pc;
}

#include "main.h"

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

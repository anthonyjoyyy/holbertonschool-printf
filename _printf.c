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
 int _printf(const char *format, ...);

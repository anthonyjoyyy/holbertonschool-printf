#include "main.h"

/**
 * finit - initalize a variable of format type
 * @f: variable to initialize
 */
 void finit(format *f)
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

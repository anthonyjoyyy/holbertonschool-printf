#include "main.h"

/**
 * prntchar - print a single char
 * @a: char to print
 */
void prntchar(char a)
{
	write(1, &a, 1);
}

/**
 */
void prntc(flag *flager, char c)
{
	if (flager == NULL)
		return;
	write(1, &c, 1);
}

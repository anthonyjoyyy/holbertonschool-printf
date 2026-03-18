#include "main.h"

/**
 * prntchar - print a single char
 * @a: char to print
 */
void prntchar(char a)
{
	write(1, &a, 1);
}

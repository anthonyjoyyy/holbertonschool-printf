#include "main.h"

/**
 * printchar - print a single char
 * @a: char to print
 */
void printchar(char a)
{
	write(1, &a, 1);
}

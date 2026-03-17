#include "main.h"

void printchar(char a)
{
	char *b = &a;
	write(1, b, 1);
}

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
 * prntc - print a character with formating
 * @flager: pointer to flag type variable
 * @c: character to print
 */
void prntc(flag *flager, char c)
{
	char *a;
	int i = 0;
	int n;

	if (flager == NULL)
		return;

	if (flager->width)
		n = flager->width;
	else
		n = 1;

	a = malloc((n + 1) * sizeof(*a));
	if (!a)
		return;

	a[n] = '\0';
	while (i < n)
	{
		a[i++] = ' ';
	}

	if (flager->minus)
		a[0] = c;
	else
		a[n-1] = c;

	while (*a)
	{
		write(1, a, 1);
		a++;
	}
}

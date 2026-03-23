#include "main.h"

/**
 * inttostr - convert an int to a string including negative
 * @i: int to convert
 * @len: length of int
 * Return: pointer to string
 */
char *inttostr(int i, int len)
{
	char *str;
	int y;
	int dig3 = i;

	if (i < 0)
	{
		str = malloc((len + 1) * sizeof(*str));
		if (!str)
			return (0);
		sinit(str, len, ' ');

		str[0] = '-';
		for (y = 1; y < len; y++)
		{
			str[y] = '0' + ((dig3 % 10) * -1);
			dig3 = dig3 / 10;
		}
		revstr(str, 1, len - 1);
	}
	else
	{
		str = malloc((len + 1) * sizeof(*str));
		if (!str)
			return (0);
		sinit(str, len, ' ');

		for (y = 0; y < len; y++)
		{
			str[y] = '0' + (dig3 % 10);
			dig3 = dig3 / 10;
		}
		revstr(str, 0, len - 1);
	}
	return (str);
}

/**
 * revstr - reverse a section of a string
 * @str: string to reverse
 * @y: first character in string to reverse
 * @x: last character in string to reverse
 */
void revstr(char *str, int y, int x)
{
	char temp;

	for (; y < x; y++, x--)
	{
		temp = str[y];
		str[y] = str[x];
		str[x] = temp;
	}
}

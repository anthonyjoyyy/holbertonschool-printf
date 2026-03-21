#include "main.h"

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

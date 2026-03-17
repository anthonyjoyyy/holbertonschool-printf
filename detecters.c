#include "main.h"

int dflag(flag *flager, const char *format, int pos)
{
	int ff = 1;

	if (flager == NULL)
		return -1;
	while (ff)
	{
		pos++;
		switch (format[pos])
		{
		case '0':
			flager->zero = 1;
			break;
		case '+':
			flager->plus = 1;
			break;
		case '-':
			flager->minus = 1;
			break;
		case ' ':
			flager->space = 1;
			break;
		default:
			ff = 0;
		}
	}
	return (pos);
}

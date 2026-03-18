#include "main.h"

/**
 * dflag - detect specified flags and mark them in flager
 * @flager: pointer to flag struct to store found flags
 * @format: main string to search flags for
 * @pos: postion in main string
 * Return: first position in string without flag
 */
int dflag(flag *flager, const char *format, int pos)
{
	int ff = 1;

	if (flager == NULL)
		return (-1);
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

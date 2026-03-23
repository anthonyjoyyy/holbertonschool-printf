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
	if (flager == NULL)
		return (-1);
	while (1)
	{
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
			return (pos);
		}
		pos++;
	}
}
/**
 * dwidth - detect and save width from string
 * @flager: pointer to flag stuct to store width
 * @format: main string to get width from
 * @pos: postion in main string
 * Return: first position in string without after width
 */
int dwidth(flag *flager, const char *format, int pos)
{
	if (flager == NULL)
		return (-1);
	while (1)
	{
		if (format[pos] <= '9' && format[pos] >= '0')
		{
			flager->width = ((flager->width * 10) + (format[pos] - '0'));
			pos++;
		}
		else
			return (pos);
	}
}

/**
 * dper - detect per and mark it in flager
 * @flager: pointer to flag struct to store found persision
 * @format: main string to search flags for
 * @pos: postion in main string
 * Return: first position in string without flag
 */
int dper(flag *flager, const char *format, int pos)
{
	if (flager == NULL)
		return (-1);
	if (format[pos] == '.')
	{
		flager->per = 0;
		pos++;
		while (1)
		{
			if (format[pos] <= '9' && format[pos] >= '0')
			{
				flager->per = ((flager->per * 10) + (format[pos] - '0'));
				pos++;
			}
			else
				return (pos);
		}
	}
	else
		return (pos);
}

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
			printf("ZERO");
			break;
		case '+':
			printf("PLUS");
			break;
		case '-':
			printf("MINUS");
			break;
		case ' ':
			printf("SPACE");
			break;
		default:
			ff = 0;
		}
	}
	return (pos);
}

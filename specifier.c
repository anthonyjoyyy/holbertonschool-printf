#include "main.h"

/**
 * specifier - call apopriate function for printing based on given char
 * @flager:
 * @
 */
void specifier(flag *flager, va_list varg, char c)
{
	switch (c)
	{
	case 'c':
		prntc(flager, va_arg(varg, int));
		break;
	case 's':
		break;
	case 'd':
		break;
	case 'f':
		break;
	default:
		break;
	}
}

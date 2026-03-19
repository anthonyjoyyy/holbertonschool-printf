#include "main.h"

/**
 * specifier - call apopriate function for printing based on given char
 * @flager:
 * @
 */
int specifier(flag *flager, va_list varg, char c)
{
	int cc;
	
	switch (c)
	{
	case 'c':
		cc = prntc(flager, va_arg(varg, int));
		return (cc);
		break;
	case 's':
		cc = prnts(flager, va_arg(varg, char *));
		return (cc);
		break;
	case 'd':
		return(0);
		break;
	case 'f':
		return(0);
		break;
	default:
		return (0);
		break;
	}
}

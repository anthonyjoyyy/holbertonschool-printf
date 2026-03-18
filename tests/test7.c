#include "../main.h"

/**
 * main - test %s printing
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
		return (-1);
	
	if ((argv[1][0] - '0') >= 1)
	{
		_printf("t1:\n");
		_printf("\texpected:\n");
		_printf("\t\tprinting [hello]    \n");
		_printf("\tresult:  \n");
		_printf("\t\tprinting [%s]   \n", "hello");
	}

	if ((argv[1][0] - '0') >= 2)
	{
		_printf("t2:\n");
		_printf("\texpected:\n");
		_printf("\t\tprinting [       hello]\n");
		_printf("\tresult:  \n");
		_printf("\t\tprinting [%12s]\n", "hello");
	}

	if ((argv[1][0] - '0') >= 3)
	{
		_printf("t3:\n");
		_printf("\texpected:\n");
		_printf("\t\tprinting [hello       ]\n");
		_printf("\tresult:  \n");
		_printf("\t\tprinting [%-12s]\n", "hello");
	}

	return (0);
}

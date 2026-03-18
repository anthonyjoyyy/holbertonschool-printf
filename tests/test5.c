#include "../main.h"

/** note: test for width will fail until the dwidth fuction is implemented */
/**
 * main - test %c printing, with flags and width
 */
int main()
{
	_printf("t1:\n");
	_printf("\texpected:\n");
	_printf("\t\tprinting [6]    \n");
	_printf("\tresult:  \n");
	_printf("\t\tprinting [%c]   \n", '6');

	_printf("t2:\n");
	_printf("\texpected:\n");
	_printf("\t\tprinting [    6]\n");
	_printf("\tresult:  \n");
	_printf("\t\tprinting [%5c]\n", '6');

	_printf("t3:\n");
	_printf("\texpected:\n");
	_printf("\t\tprinting [6    ]\n");
	_printf("\tresult:  \n");
	_printf("\t\tprinting [%-5c]\n", '6');
	
	return (0);
}

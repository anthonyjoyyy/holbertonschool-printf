#include "../main.h"

/**
 * main - test character cointing
 */
int main()
{
	int count;

	_printf("t1:\n");
	_printf("\texpect: 9\n");
	count = _printf("\t[%s]\n", "hello");
	printf("\tresult: %d\n", count);

	_printf("t2:\n");
	_printf("\texpect: 16\n");
	count = _printf("\t[%12s]\n", "");
	printf("\tresult: %d\n", count);

	_printf("t3:\n");
	_printf("\texpect: 16\n");
	count = _printf("\t[%12s]\n", "hello");
	printf("\tresult: %d\n", count);

	return (0);
}

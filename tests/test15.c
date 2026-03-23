#include <limits.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	_printf("per NULL, digit 5:[%.d]\n", 5);
	printf("per NULL, digit 5:[%.d]\n", 5);
	_printf("per 0, digit 5:[%.0d]\n", 5);
	printf("per 0, digit 5:[%.0d]\n", 5);
	_printf("per 12, digit 5:[%.12d]\n", 5);
	printf("per 12, digit 5:[%.12d]\n", 5);
	_printf("per 3, digit 500:[%.3d]\n", 500);
	printf("per 3, digit 500:[%.3d]\n", 500);
	_printf("per 3, str hello:[%.3s]\n", "hello");
	printf("per 3, str hello:[%.3s]\n", "hello");
	_printf("per 7, str hello:[%.7s]\n", "hello");
	printf("per 7, str hello:[%.7s]\n", "hello");
    return (0);
}

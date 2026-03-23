#include <limits.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len1;
	int len2;

	len1 = _printf("testing: 0 :[%d]\n", INT_MIN);
	len2 = printf("testing: 0 :[%d]\n", INT_MIN);
	_printf("Digit with width 12          :[%12d]\n", INT_MIN);
	printf("Digit with width 12          :[%12d]\n", INT_MIN);
	_printf("Digit with '-' and width 12  :[%-12d]\n", INT_MIN);
	printf("Digit with '-' and width 12  :[%-12d]\n", INT_MIN);
	_printf("Digit with '0', and width 12 :[%012d]\n", INT_MIN);
	printf("Digit with '0', and width 12 :[%012d]\n", INT_MIN);
	_printf("Digit with '+', and width 12 :[%+12d]\n", INT_MIN);
	printf("Digit with '+', and width 12 :[%+12d]\n", INT_MIN);
	_printf("Digit with ' ', and width 0  :[% d]\n", INT_MIN);
	printf("Digit with ' ', and width 0  :[% d]\n", INT_MIN);
	_printf("printing return 1 :[%d]\n", len1);
	printf("printing return 2 :[%d]\n", len2);
    return (INT_MIN);
}

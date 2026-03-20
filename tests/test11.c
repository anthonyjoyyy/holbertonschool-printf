#include <limits.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;

	len = _printf("hello %");
	printf("\n---\n");
	len2 = printf("hello %");
	printf("\n---\n");
	
	printf("len = %d\n", len);
	printf("len2 = %d\n", len2);
    return (0);
}

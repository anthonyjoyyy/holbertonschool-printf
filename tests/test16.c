#include <limits.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	_printf("width *, 7, str hello:[%*s]\n", 7, "hello");
	printf("width *, 7, str hello:[%*s]\n", 7, "hello");
	_printf("width *, 7:[%*d]\n", 7);
	printf("width *, 7:[%*d]\n", 7);
    return (0);
}

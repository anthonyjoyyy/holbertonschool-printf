#include <limits.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    _printf("Digit with width 12          :[%12d]\n", 542);
    printf("Digit with width 12          :[%12d]\n", 542);
    _printf("Digit with '-' and width 12  :[%-12d]\n", 542);
    printf("Digit with '-' and width 12  :[%-12d]\n", 542);
    _printf("Digit with '0', and width 12 :[%012d]\n", 542);
    printf("Digit with '0', and width 12 :[%012d]\n", 542);
    _printf("Digit with '+', and width 12 :[%+12d]\n", 542);
    printf("Digit with '+', and width 12 :[%+12d]\n", 542);
    _printf("Digit with ' ', and width 0  :[% d]\n", 542);
    printf("Digit with ' ', and width 0  :[% d]\n", 542);
    return (0);
}

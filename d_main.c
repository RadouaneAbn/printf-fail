#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int a = 21;
	int b = 021;
	int c = 0x21;

	_printf("Enter a = %d, b = %d, c = %d\n", a, b, c);
	_printf("Enter a = %i, b = %i, c = %i\n", a, b, c);
	printf("Enter a = %i, b = %i, c = %i\n", a, b, c);
	printf("Enter a = %d, b = %d, c = %d\n", a, b, c);
	return (0);
}

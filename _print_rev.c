#include "main.h"
/**
 * _print_rev - print a string in revers
 * @s: the string
 * Return: return the lenght of the string
 */

int _print_rev(char *s)
{
	int i, l;

	l = _strlen(s);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	for (i = l - 1; i >= 0; i--)
		write(1, &s[i], 1);
	return (l);
}

#include "main.h"
/**
 * _print_nonprintable - print non prinable char
 * @s: non printable char
 * Return: number of  printed char
 */
int _print_nonprintable(char *s)
{
	int i, tmp, c = 0;

	if (s == NULL)
		return (write(1, "(null)", 6));

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			tmp = s[i];
			if (tmp > 15)
			{
				c += write(1, "\\x", 2);
				c += _num_char(s[i], 'X', 0);
			}
			else
			{
				c += write(1, "\\x0", 3);
				c += _num_char(s[i], 'X', 0);
			}
		}
		else
			c += write(1, &s[i], 1);
	}
	return (c);
}

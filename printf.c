#include "main.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int _strlen(char *s);

/**
 * _printf - this function prints anything
 * @format: the string
 * Return: 0
 */

int _printf(const char *format, ...)
{
	long int tmp_l;
	va_list args;
	unsigned int tmp_u;
	int i, c = 0, ps = 0, space, field_width = 0;
	char *s;
	char a, len_mod;

	if (!format)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		len_mod = 'd', ps = 0;
		if (format[i] != '%' && format[i])
			write(1, &format[i], 1), c++;
		else if (format[i] == '%' && !format[i + 1])
		{
			return (-1);
		}
		else
		{
			len_mod = 'd';
			i++, space = 0, ps = 0;
			for (; format[i] == ' '; i++)
				space = 1;

			for (; format[i] == '+' || format[i] == '#'; i++)
				ps = 1;
			if (format[i] == 'h')
				len_mod = 'h', i++;

			for (; format[i] >= '0' && format[i] <= '9'; i++)
				field_width = field_width * 10 + (format[i] - '0');

			for (; field_width > 0; field_width--)
				write(1, " ", 1), c++;
			switch (format[i])
			{
				case 'c':
					a = va_arg(args, int);
					write(1, &a, 1);
					c++;
					break;
				case 's':
					s = va_arg(args, char *);
					c += _print_str(s);
					break;
				case 'S':
					s = va_arg(args, char *);
					c += _print_nonprintable(s);
					break;
				case 'i':
					tmp_l = va_arg(args, int);
					if (len_mod == 'h')
						tmp_l = (short int)tmp_l;
					if (ps && tmp_l > 0)
						c += write(1, "+", 1);
					c += _num_check(tmp_l, 'i');
					break;
				case 'd':
					tmp_l = va_arg(args, int);
					if (len_mod == 'h')
						tmp_l = (short int)tmp_l;
					if (ps && tmp_l > 0)
						c += write(1, "+", 1);
					c += _num_check(tmp_l, 'd');
					break;
				case 'u':
					tmp_u = va_arg(args, unsigned long int);
					if (len_mod == 'h')
						tmp_u = (unsigned short int)tmp_u;
					if (ps && tmp_u)
						c += write(1, "+", 1);
					c += _num_char(tmp_u, 'u', 0);
					break;
				case 'o':
					tmp_u = va_arg(args, unsigned long int);
					if (len_mod == 'h')
						tmp_u = (unsigned short int)tmp_u;
					if (ps)
						c += write(1, "0", 1);
					c += _num_char(tmp_u, 'o', 0);
					break;
				case 'x':
					tmp_u = va_arg(args, unsigned long int);
					if (len_mod == 'h')
						tmp_u = (unsigned short int)tmp_u;
					if (ps)
						c += write(1, "0x", 2);
					c += _num_char(tmp_u, 'x', 0);
					break;
				case 'X':
					tmp_u = va_arg(args, unsigned long int);
					if (len_mod == 'h')
						tmp_u = (unsigned short int)tmp_u;
					if (ps)
						c += write(1, "0x", 2);
					c += _num_char(tmp_u, 'X', 0);
					break;
				case 'b':
					tmp_u = va_arg(args, unsigned long int);
					if (len_mod == 'h')
						tmp_u = (unsigned short int)tmp_u;
					c += _num_char(tmp_u, 'b', 0);
					break;
				case 'p':
					c += _print_adresse(va_arg(args, void *));
					break;
				case 'r':
					s = va_arg(args, char *);
					c += _print_rev(s);
					break;
				case 'R':
					s = va_arg(args, char *);
					c += _print_rot(s);
					break;
				case '%':
					write(1, &format[i], 1);
					c++;
					break;
				default:
					write(1, "%", 1);
					if (ps)
					{
					if (space)
					{
					c += write(1, " ", 1);
					}
					}
					write(1, &format[i], 1);
					c += 2;
					break;
			c++;
			}
		}
	}
	va_end(args);
	return (c);
}





/**
 * _strlen - this function compute the lenght of a string
 * @s: pointer to the string
 * Return: return the lenght of the string
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

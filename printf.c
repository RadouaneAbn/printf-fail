#include "main.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int _num_char(unsigned long int n, char cs, int flag);
int _print_str(char *s);
int _num_check(long int n, char cs);
int _print_char(char c);
int _print_nonprintable(char *s);
int _print_adresse(void *p);
int _strlen(char *s);
int _print_rot(char *s);
int _print_rev(char *s);

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
	int i, c = 0, ps = 0, space;
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
			for (; format[i] == ' '; i++, space++)

			if (format[i] == '+')
				ps = 1, i++;
			else if (format[i] == 'h')
				len_mod = 'h';
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
					if (ps)
						c += write(1, "0b", 2);
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
					while (space--)
						c += write(1, " ", 1);
					write(1, &format[i - 1], 1);
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
 * _print_rot - this function encodes a string using rot13
 * @s: the string
 * Return: return the lenght of the string
 */

int _print_rot(char *s)
{
	int i, j;

	char *rot = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *ebg = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	for (i = 0; s[i] != '\0'; i++)
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
			for (j = 0; j < 52; j++)
			{
				if (s[i] == rot[j])
				{
					write(1, &ebg[j], 1);
					break;
				}
			}
		else
			write(1, &s[i], 1);
	}
	return (i);
}

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

/**
 * _num_check - convert a negative number to positive
 * @n: the number
 * @cs: conversion specifiers
 * Return: the return of _num_char
 */

int _num_check(long int n, char cs)
{
	int flag = 0;

	if (n < 0)
	{
		flag = 1;
		n *= -1;
	}
	return (_num_char(n, cs, flag));
}

/**
 * _num_char - convert a unsigned integer to string
 * @n: the integer
 * @cs: conversion specifiers
 * @flag: 0 if number is positive
 *	1 if number is negative
 * Return: the number of characters printed
 */

int _num_char(unsigned long int n, char cs, int flag)
{
	unsigned long int m, num;
	int c = 0, i, bf = 0;
	char *A, *F = "diuxXob";
	int base[9] = {10, 10, 10, 16, 16, 8, 2};

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (cs != F[bf])
		bf++;
	for (m = n; m; c++)
		m /= base[bf];

	A = (char *)malloc(c + flag);

	if (A == NULL)
		return (0);

	for (i = c + flag - 1; i >= 0; i--)
	{
		num = n % base[bf];
		if (num >= 10)
			if (cs == 'X')
				A[i] = 'A' + num - 10;
			else
				A[i] = 'a' + num - 10;
		else
			A[i] = '0' + num;
		n /= base[bf];
	}
	if (flag == 1)
		A[0] = '-';
	_print_str(A);
	free(A);
	return (c + flag);
}

/**
 * _print_str - print an array of characters
 * @s: the array (string)
 * Return: the number of characters
 */

int _print_str(char *s)
{
	int i = 0;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	for (i = 0; s[i]; i++)
		write(1, &s[i], 1);
	return (i);
}

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

/**
*_print_adresse - print the adresse
*@p: the address memory
*Return: printed char
*/
int _print_adresse(void *p)
{
	int c = 0;
	unsigned long int i = (unsigned long int) p;

	if (p == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	c += write(1, "0x", 2);
	c += _num_char(i, 'x', 0);

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

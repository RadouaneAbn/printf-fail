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

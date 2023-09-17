#include "main.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int print_i(int n);
int print_d(int n);
int _num_char(unsigned int n, char cs, int flag);
int _print_str(char *s);
int _num_check(int n, char cs);
int _print_char(char c);
int _print_nonprintable(char *s);
int _print_adresse(void *p);

/**
 * _printf - this function prints anything
 * @format: the string
 * Return: 0
 */

int _printf(const char *format, ...)
{
	va_list args;
	int tmp_d;
	unsigned int tmp_n;
	int i, c = 0;
	char *s;
	char a;

	if (!format)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%' && format[i])
			write(1, &format[i], 1), c++;
		else if (format[i] == '%' && !format[i + 1])
		{
			write(1, &format[i], 1);
			break;
		}
		else
		{
			i++;
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
				case 'i':
					tmp_d = va_arg(args, int);
					c += _num_check(tmp_d, 'i');
					break;
				case 'd':
					tmp_d = va_arg(args, int);
					c += _num_check(tmp_d, 'd');
					break;
				case 'u':
					tmp_n = va_arg(args, unsigned int);
					c += _num_char(tmp_n, 'u', 0);
					break;
				case 'o':
					tmp_n = va_arg(args, unsigned int);
					c += _num_char(tmp_n, 'o', 0);
					break;
				case 'x':
					tmp_n = va_arg(args, unsigned int);
					c += _num_char(tmp_n, 'x', 0);
					break;
				case 'X':
					tmp_n = va_arg(args, unsigned int);
					c += _num_char(tmp_n, 'X', 0);
					break;
				case 'b':
					tmp_n = va_arg(args, unsigned int);
					c += _num_char(tmp_n, 'b', 0);
					break;
				case 'S':
					s = va_arg(args, char *);
					c += _print_nonprintable(s);
					break;
				case 'p':
					c += _print_adresse(va_arg(args, void *));
					break;
				case '%':
					write(1, &format[i], 1);
					c++;
					break;
				default:
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
 * _num_check - convert a negative number to positive
 * @n: the number
 * @cs: conversion specifiers
 * Return: the return of _num_char
 */

int _num_check(int n, char cs)
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

int _num_char(unsigned int n, char cs, int flag)
{
	unsigned int m, num;
	int c = 0, i, bf = 0;
	char *A, *F = "diuxXob";
	int base[7] = {10, 10, 10, 16, 16, 8, 2};

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
 * _print_char - print a character
 * @c: the character
 * Return: 1 if char is not empty
 *	0 if else
 */

int _print_char(char c)
{
	if (c)
	{
		write(1, &c, 1);
		return (1);
	}
	return (0);
}

/**
 * _print_str - print an array of characters
 * @s: the array (string)
 * Return: the number of characters
 */

int _print_str(char *s)
{
	int i;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	for (i = 0; s[i]; i++)
	{
		if (s[i] < 32 && s[i] >= 127)
		{
			write(1, "\\x", 2);
			
		}
		write(1, &s[i], 1);
	}
	return (i);
}
/**
*_print_nonprintable - print non prinable char
*@s: non printable char
*Return: number of  printed char
*/
int _print_nonprintable(char *s)
{
	int i;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	for (i = 0; s[i]; i++)
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			 write(1, "\\x0", 4);
			_num_char((unsigned int)s[i], 'X',0);
		}
		else
		 	write(1, &s[i], 1);
	}
	return (i);
}
/**
*_print_adresse - print the adresse
*@p: the address memory
*Return: printed char
*/
int _print_adresse(void *p)
{
	unsigned long int i = (unsigned long int) p;
	if (p == NULL)
		return (0);
	return (_num_char(i, 'X', 0));
}

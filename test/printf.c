#include "main.h"
#include "main.h"
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

	if (format == NULL)
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

int _num_char(unsigned int n, char cs,int flag)
{
	unsigned int m, num;
	int c = 0, i, bf = 0;
	char *A, *F = "diuxXob";
	int base[7] = {10, 10, 10, 16, 16, 8, 2};

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

int _print_str(char *s)
{
	int i;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (0);
	}
	for (i = 0; s[i]; i++)
		write(1, &s[i], 1);
	return(i);
}

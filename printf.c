#include "main.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

int print_i(int n);
int print_d(int n);

/**
 * _printf - this function prints anything
 * @format: the string
 * Return: 0
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i, j, c = 0, tmp_n;
	char *s;
	char a;

	if (format == NULL)
		return (0);

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
			write(1, &format[i], 1), c++;
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
					j = 0;
					s = va_arg(args, char *);
					while (s[j])
					{
						write(1, &s[j], 1);
						j++;
						c++;
					}
					break;
				case 'i':
					tmp_n = va_arg(args, int);
					c += print_i(tmp_n);
					break;
				case 'd':
					tmp_n = va_arg(args, int);
					c += print_d(tmp_n);
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

int print_i(int n)
{
	int m, count = 0, i, flag = 0;
	char *A;

	for (m = n; m != 0; count++)
		m /= 10;
	if (n < 0)
	{
		flag = 1;
		n *= -1;
	}
	A = (char *)malloc(count + flag);
	if (A == NULL)
		return (0);

	for (i = count + flag - 1; i >= 0; i--)
	{
		A[i] = n % 10 + '0';
		n /= 10;
	}
	if (flag == 1)
		A[0] = '-';
	i = 0;
	for (; i <= count; i++)
		write(1, &A[i], 1);
	free(A);
	return (count);
}

int print_d(int n)
{
	int m, count = 0, i, flag = 0;
	char *A;

	for (m = n; m != 0; count++)
		m /= 10;
	if (n < 0)
	{
		flag = 1;
		n *= -1;
	}
	A = (char *)malloc(count + flag);
	if (A == NULL)
		return (0);

	for (i = count + flag - 1; i >= 0; i--)
	{
		A[i] = n % 10 + '0';
		n /= 10;
	}
	if (flag == 1)
		A[0] = '-';
	i = 0;
	for (; i <= count; i++)
		write(1, &A[i], 1);
	free(A);
	return (count);
}

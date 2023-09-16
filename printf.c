#include "main.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h> 
#include <stdarg.h>

int def(va_list args);
int print_c(va_list args);
int print_s(va_list args);
int print_i(va_list args);
int print_d(va_list args);

/**
* _printf - this function prints anything
*/

int _printf(const char *format, ...)
{
	va_list args;
	int i, j, c = 0, tmp_n;

	data op[] = {
	{'s', print_s},
	{'c', print_c},
	{'d', print_d},
	{'i', print_i},
	{'%', def},
	};

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
			write(1, &format[i], 1), c++;
		else
		{
			for (j = 0; j < 5; j++)
			{
				if (format[i + 1] == op[j].s)
				{
					tmp_n = op[j].f(args);
					i += 2;
					c += tmp_n;
				}
			}
			write(1, &format[i], 1);
			c++;
		}
	}
	va_end(args);
	return (c);
}

int def(va_list args)
{
	char tmp = va_arg(args, int);

	if (tmp == '%')
		write(1, &tmp, 1);
	return (1);
}

int print_s(va_list args)
{
	int i;
	char *s = va_arg(args, char*);

	for (i = 0; s[i]; i++)
		write(1, &s[i], 1);
	return (i);
}

int print_c(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

int print_i(va_list args)
{
	int n = va_arg(args, int);
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
	return(count);
}

int print_d(va_list args)
{
	int n = va_arg(args, int);
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
        return(count);
}

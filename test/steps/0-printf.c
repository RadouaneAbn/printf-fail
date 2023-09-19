#include "main.h"
#include "main.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h> 
#include <stdarg.h>

/**
* _printf - this function prints anything
*/

int _printf(const char *format, ...)
{
	va_list args;
	int i, j, c = 0;
	char *s;
	char a;

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

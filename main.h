#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

typedef struct format
{
	char s;
	int (*f)(va_list args);
} data;

int _printf(const char *format, ...);

#endif

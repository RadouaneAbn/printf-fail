#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

typedef struct format
{
	char s;
	int (*f)(va_list args);
} data;

int _printf(const char *format, ...);
int print_i(int n); 
int print_d(int n); 
int _num_char(unsigned int n, char cs, int flag);
int _print_str(char *s);
int _num_check(int n, char cs);
#endif

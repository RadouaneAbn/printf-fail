#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <limits.h>

int _printf(const char *format, ...);

int _num_char(unsigned long int n, char cs, int flag);
int _print_str(char *s);
int _num_check(long int n, char cs);
int _print_nonprintable(char *s);
int _print_adresse(void *p);
int _print_rot(char *s);
int _print_rev(char *s);
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

#endif

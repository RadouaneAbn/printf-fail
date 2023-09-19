#include "main.h"

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


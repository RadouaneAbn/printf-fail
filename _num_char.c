
/**
 * _num_char - convert a unsigned integer to string
 * @n: the integer
 * @cs: conversion specifiers
 * @flag: 0 if number is positive
 *      1 if number is negative
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

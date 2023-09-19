#include "main.h"
/**
 * _num_check - convert a negative number to positive
 * @n: the number
 * @cs: conversion specifiers
 * Return: the return of _num_char
 */

int _num_check(long int n, char cs)
{
        int flag = 0;

        if (n < 0)
        {
                flag = 1;
                n *= -1;
        }
        return (_num_char(n, cs, flag));
}


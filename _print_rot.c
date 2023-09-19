#include "main.h"
/**
 * _print_rot - this function encodes a string using rot13
 * @s: the string
 * Return: return the lenght of the string
 */

int _print_rot(char *s)
{
	int i, j;

	char *rot = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *ebg = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	for (i = 0; s[i] != '\0'; i++)
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
			for (j = 0; j < 52; j++)
			{
				if (s[i] == rot[j])
				{
					write(1, &ebg[j], 1);
					break;
				}
			}
		else
			write(1, &s[i], 1);
	}
	return (i);
}

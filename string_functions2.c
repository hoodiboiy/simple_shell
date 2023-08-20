#include "shell.h"

/**
 * _strncmp - Compares two strings.
 * @s1: The first string.
 * @s2: The second string.
 * @n: number of bytes
 * Return: an int > 0 if s1 is smaller than s2, and int < 0 if bigger and
 * an int = 0 if srings are the same.
 */

int _strncmp(char *s1, char *s2, int n)
{
	int ret = 0;

	while (n && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (!n)
		return (0);
	ret = *s1 - *s2;
	return (ret);
}

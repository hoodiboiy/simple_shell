#include "shell.h"

/**
 * _strcpy - Copies string pointed to by source to dest.
 * @dest: Buffer to copy to.
 * @src: Buffer to copy from.
 *
 * Return: void.
 */
char *_strcpy(char *dest, char *src)
{
	int j;

	for (j = 0; src[j] != '\0'; j++)
		dest[j] = src[j];
	dest[j] = src[j];

	return (dest);
}

/**
 * _strlen - Counts length of a string.
 * @s: The string.
 *
 * Return: length of the string.
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
		length++;

	return (length);
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: an int > 0 if s1 is smaller than s2, and int < 0 if bigger and
 * an int = 0 if srings are the same.
 */
int _strcmp(char *s1, char *s2)
{
	int ret = 0;

	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	ret = *s1 - *s2;
	return (ret);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: Destination string.
 * @src: Source string.
 *
 * Return: Pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	char *string = dest;

	while (*string)
		string++;
	while (*src)
		*string++ = *src++;
	*string = '\0';
	return (dest);
}

/**
 * _strdup -  returns a pointer to a newly allocated space in memory, which
 * contains a copy of the string given as a parameter.
 * @str: string given as parameter.
 * Return: NULL if str = NULL. On success, the _strdup function returns a
 * pointer to the duplicated string. It returns NULL if insufficient memory was
 * available.
 */
char *_strdup(char *str)
{
	char *cpy, *tmp;
	int len = 0;

	if (str == NULL)
		return (NULL);
	while (str[len] != '\0')
		len++;
	cpy = malloc(sizeof(char) * (len + 1));
	if (cpy == NULL)
		return (NULL);
	tmp = cpy;
	while (*str)
		*tmp++ = *str++;
	*tmp = '\0';
	return (cpy);
}


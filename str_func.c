#include "main.h"

/**
 * _strchr - search character in string
 * @s: string
 * @c: character
 * Return: first occurence or NUll
 */

char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

/**
 * _strlen - length of string
 * @p: string
 * Return: length
 */

int _strlen(char *p)
{
	int len = 0;

	while (*(p + len) != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _strcat - concatenates two string
 * @dest: first param
 * @scr: second param
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	int len_dest, i;

	len_dest = _strlen(dest);
	for (i = 0; src[i] != '\0' && i < len_dest; i++)
		dest[len_dest + i] = src[i];
	dest[len_dest + i] = '\0';
	return (dest);
}

/**
 * _strcat - concatenates two string
 * @dest: first param
 * @src: second param
 * Return: pointer to dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int len_dest, i;

	len_dest = _strlen(dest);
	for (i = 0; src[i] != '\0' && i < n; i++)
		dest[len_dest + i] = src[i];
	dest[len_dest + i] = '\0';
	return (dest);
}

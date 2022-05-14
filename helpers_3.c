#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: first param
 * @accept: second param
 * Return: return length
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int len = 0;

	while (*s && _strchr(accept, *s++))
		len++;
	return (len);
}

/**
 * _strcspn - scan s1 until the first occurrence of any
 * characters that are part of s2
 * @s1: first param
 * @s2: second param
 * Return: return length of string s1 if
 * no characters of s1 matched to s2
 */

size_t _strcspn(char *s1, char *s2)
{
	unsigned int len = 0;

	if (!s1 || !s2)
		return (len);
	while (*s1)
	{
		if (_strchr(s2, *s1))
			return len;
		else
		{
			s1++;
			len++;
		}
	}
	return (len);
}

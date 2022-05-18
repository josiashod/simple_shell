#include "main.h"

/**
 * arr_size - determine the lentgh
 * of the array
 * @str: the given string of strtow
 * @delim: delimeter
 *
 * Return: array size
 */
int arr_size(char *str, char *delim)
{
	int i = 0, size = 0;

	while (str[i])
	{
		while (str[i] == *delim)
			i++;
		if (str[i] != *delim && str[i])
		{
			size++;
			while (str[i] && str[i] != *delim)
				i++;
		}
	}
	return (size);
}

/**
* _split - splits a stirng into words
* @str: string to be splitted
* @delim: delimeter
*
* Return: pointer to the array of splitted words
*/
char **_split(char *str, char *delim)
{
	char **split, *token;
	int size = arr_size(str, delim), i = 0;

	if (size == 0)
		return (NULL);
	split = (char **) malloc(sizeof(char *) * (size + 1));

	if (!split)
		return (NULL);

	token = strtok(str, delim);
	while (token)
	{
		split[i] = token;
		i++;
		token = strtok(NULL, delim);
	}
	split[i] = NULL;
	return (split);
}

/**
 * _memcpy - copies memory area.
 * @dest: destination
 * @src: source
 * @n: number of bytes.
 *
 * Return: a pointer to dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	for (; i < n; i++)
		dest[i] = src[i];

	return (dest);
}

/**
 * _strtok - breaks a string into a sequence
 * of zero or more nonempty tokens
 * @str: the string to be parsed
 * @delim: specifies a set of bytes that delimit the
 * tokens in the parsed string
 * Return: return a pointer to the next token,
 * or NULL if there are no more tokens
 */
/*char *_strtok(char *str, char *delim)
{
	static char *olds;

	return (_mystrtok_r(str, delim, &olds));
}*/
/**
 * _mystrtok_r - parse str into tokens separated
 * by characters in delim
 * @str: the string to be parsed
 * @delim: specifies a set of bytes that delimit the
 * tokens in the parsed string
 * @buffer: pointer to pointer
 * Return: NULL or token
 */
/*char *_mystrtok_r(char *str, char *delim, char **buffer)
{
	char *end;

	if (str == NULL)
		str = *buffer;
	if (*str == '\0')
	{
		*buffer = str;
		return (NULL);
	}

	str += _strspn(str, delim);
	if (*str == '\0')
	{
		*buffer = str;
		return (NULL);
	}

	end = str + _strcspn(str, delim);
	if (*end == '\0')
	{
		*buffer = end;
		return (str);
	}

	*end = '\0';
	*buffer = end + 1;
	return (str);
}*/

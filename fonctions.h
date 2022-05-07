#include "main.h"

/**
 * string_to_array - splits a string and returns
 * an array of each word of the string.
 * @buffer: command string
 * @delim: separator
 * Return: array of each word of the string
 */

char **string_to_array(char *buffer, char *delim)
{
	char **cmd = NULL;
	char *token = NULL;
	size_t i = 0;
	
	token = strtok(buffer, delim);
	while (token != NULL)
	{
		cmd = (char **)realloc(cmd, (sizeof(char *) * (i + 1)));
		cmd[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	cmd = (char **)realloc(cmd, (sizeof(char *) * (i + 1)));
	cmd[i] = NULL;
	return (cmd);
}

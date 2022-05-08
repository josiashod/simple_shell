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

/**
 * handle_path - change path to complete path
 * @command: command to change complete path from
 * Return: complete path
 */

char *handle_path(char *command)
{
	char *path = NULL;
	char **directorys;
	char *cwd = NULL;
	struct stat st;
	int i = 0;
	char str = '/';

	cwd = getcwd(cwd, 0);
	path = getenv("PATH");
	directorys = string_to_array(path, ":");
	
	while (directorys[i] != NULL)
	{
		chdir(directorys[i]);
		if (stat(command, &st) == 0)
		{
			directorys[i] = _strncat(directorys[i], &str, 1);
			command = _strcat(directorys[i], command);
			break;
		}
		i++;
	}
	chdir(cwd);
	return (command);
}

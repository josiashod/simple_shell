#include "main.h"

/**
 * get_command_type - determine the type of the command
 * @path: list of command director
 * @command: the command to check
 *
 * Return: constant representing the type of the command
 * Description -
 *              EXTERNAL_COMMAND (1) command like "/bin/ls"
 *              INTERNAL_COMMAND (2) command like exit, env
 *              PATH_COMMAND (3) command found in path
 *              INVALID_COMMAND (-1) invalid command
 */
int get_command_type(list_t *path, char *command)
{
	int i;
	char *internal_commands[] = {"env", "exit", "setenv", "unsetenv", NULL}, *dir;

	if (_strchr(command, '/'))
		return (EXTERNAL_COMMAND);

	for (i = 0; internal_commands[i]; i++)
	{
		if (_strcmp(command, internal_commands[i]) == 0)
			return (INTERNAL_COMMAND);
	}

	dir = _search(path, command);
	if (dir)
		return (PATH_COMMAND);

	return (INVALID_COMMAND);
}

/**
 * get_func - selects the correct function
 * to execute
 * @command: the command to execute
 *
 * Return: pointer to the function that corresponds
 * to the function tha should be executed
 */
void (*get_func(char *command))(list_t *path, char **args)
{
	func_t funcs[] = {
		{"env", env},
		{"setenv", handle_setenv},
		{"unsetenv", handle_unsetenv},
		{"exit", handle_exit},
		{NULL, NULL}
	};
	int i = 0;

	while (i < 4)
	{
		if (_strcmp(command, funcs[i].command_name) == 0)
			return (funcs[i].func);
		i++;
	}

	return (NULL);
}

/**
 * _getenv - gets an environment variable.
 * @name: name of the var
 *
 * Return: pointer to the variable
 */
char *_getenv(const char *name)
{
	int i, found;
	char **env = environ;

	while (*env)
	{
		for (i = 0; *(*env + i) != '='; i++)
		{
			found = 1;
			if (*(name + i) != *(*env + i))
			{
				found = 0;
				break;
			}
		}
		i++;
		if (found)
			return ((*env + i));

		env++;
	}

	return (NULL);
}

/**
 * _setenv - set an environment variable.
 * @name: name of the var
 * @value: the new value
 * @overwrite: perform changement
 *
 * Return: 0 on success, -1 on failure
 */
int _setenv(char *name, char *value, int overwrite)
{
	int i, status, j = 0;
	char **cp_env = environ;
	int len;

	while (*cp_env)
	{
		for (i = 0; *(*cp_env + i) != '='; i++)
		{
			status = 1;
			if (*(name + i) != *(*cp_env + i))
			{
				status = 0;
				break;
			}
		}
		i++;
		if (status)
		{
			if (overwrite)
				_memcpy((*cp_env + i), value, _strlen(value) + 1);
			return (1);
		}
		cp_env++;
		j++;
	}

	if (overwrite)
	{
		len = _strlen(name) + _strlen(value) + 1;
		*cp_env = malloc(sizeof(char) * len);

		if (!(*cp_env))
			return (-1);

		_strcat(_strcat(_strcat(*cp_env, name), "="), value);
		cp_env++;
		*cp_env = NULL;
		return (0);
	}
	return (-1);
}

/**
 * _unsetenv - set an environment variable.
 * @name: name of the var
 *
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(char *name)
{
	int i, status, j = 0;
	char **cp_env = environ;

	while (*cp_env)
	{
		for (i = 0; *(*cp_env + i) != '='; i++)
		{
			status = 1;
			if (*(name + i) != *(*cp_env + i))
			{
				status = 0;
				break;
			}
		}
		if (status)
		{
			while (*cp_env)
			{
				*cp_env = *(cp_env + 1);
				if (*(cp_env + 1))
					cp_env++;
			}
		}
		cp_env++;
		j++;
	}
	return (0);
}

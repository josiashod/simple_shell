#include "main.h"

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

/**
 * _cd - change the current directory
 * @dir: the new directory
 *
 * Return: 1 on success, 0 on fail or -1 on error
 */
int _cd(char *dir)
{
	char *cwd = NULL, *home_dir = _getenv("HOME");

	cwd = getcwd(cwd, 0);

	if (_strlen(dir) == 0)
		dir = home_dir;
	if (_strcmp(dir, "-") == 0)
	{
		if (!_getenv("OLDPWD"))
		{
			print(_getenv("_"), STDERR_FILENO);
			print(": cd: << OLDPWD >> non défini\n", STDERR_FILENO);
			return (-1);
		}

		_memcpy(dir, _getenv("OLDPWD"), _strlen(_getenv("OLDPWD")) + 1);
	}

	if (chdir(dir) == 0)
	{
		if (_setenv("PWD", dir, 1) == -1)
		{
			chdir(cwd);
			return (0);
		}
		if (_setenv("OLDPWD", cwd, 1) == -1)
		{
			chdir(cwd);
			_setenv("PWD", cwd, 1);
			return (0);
		}
		return (1);
	}

	return (0);
}

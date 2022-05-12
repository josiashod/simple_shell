#include "main.h"

/**
 * env - print the environ
 * @path: list of directory in path
 * @args: list of arguments
 */
void env(list_t *path __attribute__((unused)),
char **args __attribute__((unused)))
{
	char **env;

	env = environ;
	while (*env)
	{
		print(*env, STDOUT_FILENO);
		print("\n", STDOUT_FILENO);
		env++;
	}
}

/**
 * handle_exit - exit the shell
 * @path: list of directory in path
 * @args: list of arguments
 */
void handle_exit(list_t *path, char **args)
{
	int code, nb_arg = 0;

	while (args[nb_arg])
		nb_arg++;

	if (nb_arg == 1)
	{
		free_list(path);
		free(args);
		exit(0);
	}
	if (nb_arg == 2)
	{
		code = _atoi(args[1]);
		if (code == -1)
		{
			print(_getenv("_"), STDERR_FILENO);
			print(": exit: Illegal number\n", STDERR_FILENO);
			return;
		}
		free(args);
		free_list(path);
		exit(code);
	}
	if (nb_arg > 2)
	{
		print(_getenv("_"), STDERR_FILENO);
		print(": exit: take no more than one argument\n", STDERR_FILENO);
		return;
	}
}

/**
 * handle_setenv - handle setenv function.
 * @path: list of directory in path
 * @args: list of arguments
 */
void handle_setenv(list_t *path __attribute__((unused)), char **args)
{
	int status, nb_arg = 0;

	while (args[nb_arg])
		nb_arg++;

	if (nb_arg < 3 || nb_arg > 3)
	{
		print(_getenv("_"), STDERR_FILENO);
		print(": setenv: missing VARIABLE && VALUE\n", STDERR_FILENO);
		return;
	}
	if (_strchr(args[1], '='))
	{
		print(_getenv("_"), STDERR_FILENO);
		print(": setenv: VARIABLE should not contain '='\n", STDERR_FILENO);
		return;
	}

	status = _setenv(args[1], args[2], 1);

	if (status == -1)
	{
		print(_getenv("_"), STDERR_FILENO);
		print(": setenv: something went wrong", STDERR_FILENO);
		return;
	}
}

/**
 * handle_unsetenv - handle unsetenv function.
 * @path: list of directory in path
 * @args: list of arguments
 */
void handle_unsetenv(list_t *path __attribute__((unused)), char **args)
{
	int status, nb_arg = 0;

	while (args[nb_arg])
		nb_arg++;

	if (nb_arg < 2 || nb_arg > 2)
	{
		print(_getenv("_"), STDERR_FILENO);
		print(": unsetenv: missing VALUE\n", STDERR_FILENO);
		return;
	}

	status = _unsetenv(args[1]);

	if (status == -1)
	{
		print(_getenv("_"), STDERR_FILENO);
		print(": unsetenv: something went wrong", STDERR_FILENO);
		return;
	}
}

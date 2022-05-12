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

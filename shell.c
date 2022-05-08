#include "main.h"
#include "errors.h"

/**
 * _getline - this function handle
 * line reading
 * @line: the address of the line
 * @stream: the file to read
 *
 * Return: on success the number of
 * caracteres read, on fails -1
 */
ssize_t _getline(char **line, FILE *stream)
{
	ssize_t ret;
	size_t n = 0;

	printf("($) ");
	ret = getline(line, &n, stream);

	return (ret);
}

/**
 * _execve - execute the command
 * @arg: the array of argument to execute
 *
 * Return: -1 on error
 */
void _execve(char **arg)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
		perror(SOMWTWRG);
	if (pid == 0)
	{
		if (execve(arg[0], arg, NULL) == -1)
		{
			perror(getenv("PWD"));
			exit(2);
		}
	}
	else
		waitpid(pid, &status, 0);
}

/**
 * non_interactive - the function handle the
 * non-interactive mode off the shell
 * @args: list of argument
 * @path: list of command directory
 */
void non_interactive(list_t *path __attribute__((unused)), char *exec_path __attribute__((unused)))
{
	char *line, delim = '\n', **args;
	ssize_t i = 0;

	while(_getline(&line, stdin) != -1)
	{
		/* remove new line */
		strtok(line, &delim);
		args = _split(line, ";");

		for(i = 0; args[i]; i++)
		{
			printf("%s\n", args[i]);
		}
		if (!args[i])
			break;
	}
	free(args);
	free(line);
}


/**
 * interactive - the function handle the
 * interactive mode off the shell
 * @path: list of command directory
 * @exec_path: the path of the executable 
 */
void interactive(list_t *path, char *exec_path)
{
	char *cmd, *line, delim = '\n', **args;
	ssize_t read = 0;

	while (1)
	{
		read = _getline(&line, stdin);
		if (read > 1)
		{
			cmd = strtok(line, &delim);
			args = _split(cmd, " ");

			if (_strchr(args[0], '/'))
				_execve(args);
			else
			{
				cmd = _search(path, args[0]);
				if (!cmd)
				{
					perror(exec_path);
				}
				else
				{
					args[0] = cmd;
					_execve(args);
				}
			}
			free(args);
		}
	}
	free(line);
}

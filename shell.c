#include "main.h"
#include "errors.h"
/**
 * main - Entry point
 *
 * Return: returns EXIT_FAILURE OF EXIT_SUCCESS
 *
 */

int main(int argc  __attribute__((unused)), char *argv[])
{
	char *buffer = NULL;
	size_t bufsize = 0;
	int status;
	pid_t child_pid;
	int cmd_stat;
	struct stat st;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		if (getline(&buffer, &bufsize, stdin) < 0)
			break;
		if (buffer == NULL)
			exit(0);

		argv = string_to_array(buffer, "\n");
		if (argv[0] == NULL)
		{	free(argv);
			continue;
		}

		cmd_stat = stat(argv[0], &st);
		if (cmd_stat == -1)
			perror(INVALID_COMMAND);

		child_pid = fork();
		if (child_pid == -1)
		{
			write(STDOUT_FILENO, FORK_FAILED, strlen(FORK_FAILED));
		}
		else if (child_pid == 0)
		{
			status = execve(argv[0], argv, NULL);
		}
		else if (child_pid > 0)
		{
			wait(&status);
		}
		free(argv);
	}

	printf("\n");
	free(buffer);
	return (0);
}

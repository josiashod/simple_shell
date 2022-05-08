#include "main.h"

/**
 * print_error - this function print error
 * @shell_name: the name of the shell
 * @command: the command is entered by the user
 * @line: the line where the command is not good
 * @mode: is interactive or non-interactive
 * Description -
 *				INTERACTIVE (1)
 *				NON-INTERACTIVE (0)
 */
void print_error(char *shell_name, char *command,
int line __attribute__((unused)), int mode)
{
	print(shell_name, STDERR_FILENO);
	print(": ", STDERR_FILENO);
	if (!mode)
	{
		/*print(line - '0', STDERR_FILENO);*/
		print(" 1: ", STDERR_FILENO);
	}
	print(command, STDERR_FILENO);
	print(": not found\n", STDERR_FILENO);
}

/**
 * print - print message
 * @str: string to print
 * @stream: stream to print out
 */
void print(char *str, int stream)
{
	int i = 0;

	for (; str[i]; i++)
		write(stream, &str[i], 1);
}

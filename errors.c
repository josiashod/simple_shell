#include "main.h"

/**
 * print_error - this function print error
 * @exec: the path of the executable
 * @command: the name of the command
 * @message: the message to print
 */
void print_error(char *exec, char *command, char *message)
{
	char error[1024] = {0};

	_strcat(error, exec);
	_strcat(error, ": 1: ");
	_strcat(error, command);
	_strcat(error, ": ");
	_strcat(error, message);
	_strcat(error, "\n");
	write(STDOUT_FILENO, error, _strlen(error));
	/*perror(error);*/
}

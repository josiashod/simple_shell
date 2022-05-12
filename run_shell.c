#include "main.h"

/**
 * main - the main entry of the shell
 * @argc: the number of arguments
 * @argv: array of arguments.
 * Return: exit code
 */
int main(int argc __attribute__((unused)),
char **argv __attribute__((unused)))
{
	list_t *path = NULL;

	path = init_path(&path);
	if (!isatty(STDIN_FILENO))
	{
		non_interactive(path);
	}
	else
	{
		interactive(path);
	}
	free_list(path);
	exit(0);
}

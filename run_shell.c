#include "main.h"

list_t *path = NULL;

void ctrc_handler(int sig_num __attribute__((unused)))
{
    fflush(stdout);
	print("\n", STDOUT_FILENO);
	free_list(path);
	exit(0);
}

/**
 * main - the main entry of the shell
 * @argc: the number of arguments
 * @argv: array of arguments.
 * Return: exit code
 */
int main(int argc __attribute__((unused)),
char **argv __attribute__((unused)))
{

	signal(SIGINT, ctrc_handler);

	path = init_path(&path);
	if (!isatty(STDIN_FILENO))
	{
		non_interactive(path);
	}
	else
	{
		interactive(path);
	}
	print("ui", STDOUT_FILENO);
	free_list(path);
	exit(0);
}

#include "main.h"

void env(list_t *path __attribute__((unused)), char **args)
{
    char **env;

    printf("oui");
    env = environ;
    while (*env)
    {
        print(*env, STDOUT_FILENO);
        env++;
    }

    free(args);
}

void handle_exit(list_t *path, char **args)
{
    free_list(path);
    free(args);

    exit(2);
}
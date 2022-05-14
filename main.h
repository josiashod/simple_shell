#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <signal.h>
#include <fcntl.h>

extern char **environ;

#define EXTERNAL_COMMAND  1
#define INTERNAL_COMMAND 2
#define PATH_COMMAND 3
#define INVALID_COMMAND -1

#define INTERACTIVE_MODE 1
#define NON_INTERACTIVE_MODE 0


/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

/**
 * struct func - Struct func
 *
 * @command_name: The name of the command to handle
 * @func: The function associated
 */
typedef struct func
{
	char *command_name;
	void (*func)(list_t *path, char **args);
} func_t;

/* HELPERS */
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
char *_memcpy(char *dest, char *src, unsigned int n);
int _strcmp(char *s1, char *s2);
char **_split(char *str, char *delim);
int _atoi(char *s);
char * _mystrtok_r(char *str, char *delim, char **save_ptr);
char * _strtok(char *str, char *delim);
unsigned int _strspn(char *s, char *accept);
size_t _strcspn(char *s1, char *s2);

/* PATH HANDLERS */
list_t *add_node_end(list_t **head, char *str);
void free_list(list_t *head);
list_t *init_path(list_t **head);
char *_search(list_t *path, char *str);

/* BUILT-IN HANDLERS */
void (*get_func(char *command))(list_t *path, char **args);
void handle_exit(list_t *path, char **args);
void env(list_t *path, char **args);
void handle_setenv(list_t *path, char **args);
void handle_unsetenv(list_t *path, char **args);
void handle_cd(list_t *path __attribute__((unused)), char **args);

/* BUILT-IN FUNCTIONS */
char *_getenv(const char *name);
int _setenv(char *name, char *value, int overwrite);
int _unsetenv(char *name);
int _cd(char *cd);

/* SHELL FUNCTIONS */
ssize_t _getline(char **line, int mode);
void _execve(list_t *path, char **args, int command_type);
void execute_command(list_t *path, char **args, int command_type);
int get_command_type(list_t *path, char *command);
void print(char *str, int stream);
void print_number(int n, int stream);
void print_error(char *command, int line, int mode);

/* SHELL MODE HANDLERS */
void non_interactive(list_t *path);
void interactive(list_t *path);

#endif /* MAIN_H */

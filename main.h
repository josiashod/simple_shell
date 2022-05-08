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
 * @func: The function to execute
 * @f: The function associated
 */
typedef struct func
{
	char *command_name;
	void (*func)();
} func_t;

/* HELPERS */
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
char **_split(char *str, char *delim);

/* PATH HANDLER */
list_t *add_node_end(list_t **head, char *str);
void free_list(list_t *head);
list_t *init_path(list_t **head);
char *_search(list_t *path, char *str);
void print_error(char *exec, char *command, char *message);

/* BUILT-IN FUNCTIONS */
void handle_exit(void);
void env(void);
void (*get_func(char *command))(void);


/* SHELL FUNCTIONS */
ssize_t _getline(char **line, FILE *stream);
void _execve(char **arg);
void interactive(list_t *path, char *exec_path);
void non_interactive(list_t *path, char *exec_path);

#endif /* MAIN_H */

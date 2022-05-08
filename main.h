#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>

char *handle_path(char *command);
char **string_to_array(char *buffer, char *delim);
char *_strncat(char *dest, char *src, int n);
int string_length(char *p);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
#endif

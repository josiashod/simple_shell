#ifndef MAIN_H
#define MAIN_H

const char *FORK_FAILED = "Fork failed";
const char *INVALID_COMMAND = "Invalid command";

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

char **string_to_array(char *buffer, char *delim);

#endif

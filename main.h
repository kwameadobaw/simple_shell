#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

void execute_command(const char *input);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
ssize_t my_getline(char *input, size_t max_length);

#endif

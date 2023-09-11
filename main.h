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
char *get_full_path(const char *command);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void handle_exit(char **input);
int _atoi(char *s);
int _strncmp(const char *str1, const char *str2, size_t n);

#endif

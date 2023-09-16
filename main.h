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
#define MAX_ENV_VARS 1000
#define PATH_DELIMITER ":"

void execute_command(const char * const args[]);
int _strcmp(char *s1, char *s2);
int _strlen(const char *s);
ssize_t my_getline(char *input, size_t max_length);
char *get_full_path(const char *command);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
void handle_exit(char **input);
int _atoi(char *s);
int _strncmp(const char *str1, const char *str2, size_t n);
extern char **environ;
int setenv_command(char **args);
int unsetenv_command(char **args);
char *get_full_path(const char *command);
void print_environment();

#endif

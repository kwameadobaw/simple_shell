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
int unset_env(const char *variable);
int set_env(const char *variable, const char *value);
int change_directory(const char *new_dir, char *prev_dir, char **env);
extern char **environ;
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);

#endif

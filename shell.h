#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

#define TOK_DELIM " \t\r\n\a\""

/* Function Prototypes */
void shell_interactive(void);
void shell_no_interactive(void);
char *read_line(void);
char **split_line(char *line);
int execute_args(char **args);
int new_process(char **args);
char *read_stream(void);
char *get_path(char *command);

/* Builtin Functions */
int own_cd(char **args);
int own_exit(char **args);
int own_env(char **args);
int own_setenv(char **args);
int own_unsetenv(char **args);
void handle_exit(char **input);

#endif

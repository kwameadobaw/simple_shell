#include "shell.h"
/**
 * own_setenv - Set an environment variable or modify an existing one
 * @args: AN array of strings containing command arguments.
 *
 * Return: 1 on success, or 1 with error message to stderr on failure
*/
int own_setenv(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return (1);
	}
	if (setenv(args[1], args[2], 1) != 0)
	{
		perror("setenv");
	}
	return (1);
}
/**
 * own_unsetenv - Unset an environment variable
 * @args: AN array of strings containing command arguments.
 * Return: 1 on success, or 1 with error message to stderr on failure.
*/
int own_unsetenv(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return (1);
	}
	if (unsetenv(args[1]) != 0)
	{
		perror("unsetenv");
	}
	return (1);
}

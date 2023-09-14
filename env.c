#include "main.h"
/**
 * setenv_command - Implement the setenv command
 * @args: Array of command arguments 
 * Return: 0 on success, 1 on failure
*/
int setenv_command(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return (1);
	}
	if (setenv(args[1], args[2], 1) != 0)
	{
		perror("setenv");
		return (1);
	}
	return (0);
}
/**
 * unsetenv_command - Implement the unsetenv command
 * @args: Array of command arguments
 * Return: 0 on success, 1 on failure
*/
int unsetenv_command(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return (1);
	}
	if (unsetenv(args[1]) != 0)
	{
		perror("unsetenv");
		return (1);
	}
	return (0);
}

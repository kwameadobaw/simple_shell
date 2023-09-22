#include "shell.h"
/**
 * own_exit - exit the shell
 * @args: command to be run
 * Return: Always 0;
 */
int own_exit(char **args)
{
	int status = 0;

	if (args[1] != NULL)
	{
		status = _atoi(args[1]);

		exit(status);
	}
	exit(status);
}

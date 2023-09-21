#include "shell.h"
/**
 * own_exit - exit the shell
 * @args: command to be run
 * Return: Always 0;
 */
int own_exit(char **args)
{
	if (args[1] != NULL)
	{
		int status = atoi(args[1]);

		exit(status);
	}
	exit(EXIT_SUCCESS);
}

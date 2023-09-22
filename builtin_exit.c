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
		char *endptr;
		long status = strtol(args[1], &endptr, 10);
	/*	status = _atoi(args[1]); */

		/*exit(status);*/
		if (*endptr != '\0')
		{
			fprintf(stderr, "Usage: exit status\n");
			return (1);
		}
		exit((int)status);
	}
	exit(0);
}

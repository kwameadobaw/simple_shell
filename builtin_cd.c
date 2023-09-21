#include "shell.h"
/**
 * own_cd - change the current dir
 * @args: An array of strings containing command arguments.
 * Return: 1 to indicate the command has been executed successfully.
 */
int own_cd(char **args)
{
	if (args[1] == NULL)
		fprintf(stderr, "Usage: cd DIRECTORY\n");
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
		}
	}

	return (1);
}

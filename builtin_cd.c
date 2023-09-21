#include "shell.h"
/**
 * own_cd - change the current dir
 * @args: An array of strings containing command arguments.
 * Return: 1 to indicate the command has been executed successfully.
 */
int own_cd(char **args)
{
	char *new_dir;

	if (args[1] == NULL || strcmp(args[1], "~") == 0)
	{
		new_dir = getenv("HOME");
	}
	else if (strcmp(args[1], "-") == 0)
	{
		new_dir = getenv("OLDPWD");
	}
	else
	{
		new_dir = args[1];
	}
	if (chdir(new_dir) != 0)
	{
		perror("cd");
	}
	else
	{
		char cwd[1024];
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			setenv("PWD", cwd, 1);
			setenv("OLDPWD", new_dir, 1);
		}
	}
	return (1);
}

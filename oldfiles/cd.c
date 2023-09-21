#include "main.h"
/**
 * change_directory - Change the current working directory
 * @path: The path to change to
 *
 * This function changes the current working directory to the specified path.
 * If the paht is empty or a space, it changes to the home directory
 * If the path is "-", it changes to the previous working directory.
 *
 * Return: 0 on success, -1 on failure
*/
int change_directory(char *path)
{
	char *new_pwd;

	if (chdir(path) != 0)
	{
		perror("cd");
		return (-1);
	}
	new_pwd = getcwd(NULL, 0);

	if (new_pwd == NULL)
	{
		perror("getcwd");
		return (-1);
	}
	if (setenv("PWD", new_pwd, 1) != 0)
	{
		perror("setenv");
		return (-1);
	}
	write(STDOUT_FILENO, new_pwd, _strlen(new_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(new_pwd);
	return (0);
}

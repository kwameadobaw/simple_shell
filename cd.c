#include "main.h"
/**
 * change_directory - Change the current working directory
 * @new_dir: The directory to change to (NULL for home directory)
 * @prev_dir: The previous directory (for handling "cd -" command)
 * @env: The environment variables
 *
 * Return: 1 on success, 0 on failure
*/
int change_directory(const char *new_dir, char *prev_dir, char **env)
{
	char *home_dir = _getenv("HOME", env);
	char *cwd;

	if (new_dir == NULL)
		new_dir = home_dir;

	if (new_dir != NULL && _strcmp(new_dir, "-") == 0)
	{
		if (prev_dir != NULL)
		{
			char newline = '\n';
			write(STDOUT_FILENO, prev_dir, _strlen(prev_dir));
			write(STDOUT_FILENO, &newline, 1);
			chdir(prev_dir);
		}
	}
	else
	{
		if (chdir(new_dir) == -1)
		{
			perror("cd");
			return (0);
		}
	}
	cwd = getcwd(NULL, 0);

	if (cwd != NULL)
	{
		_setenv("PWD", cwd, env);
		free(cwd);
	}

	return (1);
}

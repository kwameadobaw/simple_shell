#include "shell.h"
/**
 * get_path - Get the full path of a acommand by searching in the PATH
 * @command: The comand to search for
 *
 * Return: The full path of the command, or NULL if not found in the PATH
*/
char *get_path(char *command)
{
	char *path = getenv("PATH");
	char *dir = strtok(path, ":");
	struct stat buffer;
	char *full_path;

	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		snprintf(full_path, strlen(dir) + strlen(command) + 2, "%s/%s",
				dir, command);

		if (stat(full_path, &buffer) == 0 &&
				S_ISREG(buffer.st_mode) &&
				(buffer.st_mode & S_IXUSR))
		{
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	return (NULL);
}

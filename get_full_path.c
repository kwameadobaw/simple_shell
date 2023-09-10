#include "main.h"
/**
 * get_full_path - Find the full path to an executable in the PATH variable
 * @command: The name of the executable to search for
 *
 * Return: The full path to the executable if found, otherwise NULL
*/
char *get_full_path(const char *command)
{
	char *path = getenv("PATH");
	char *token;
	char full_path[1024];

	if (path == NULL)
		return (NULL);

	token = strtok(path, ":");

	while (token != NULL)
	{
		sprintf(full_path, "%s/%s", token, command);

		if (access(full_path, X_OK) == 0)
		{
			return (strdup(full_path));
		}
		token = strtok(NULL, ":");
	}
	return  (NULL);
}

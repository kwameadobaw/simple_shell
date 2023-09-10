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
	char *full_path = NULL;
	char *token;
	char *path_copy;
	char *saveptr = NULL;

	size_t command_len, path_len;

	if (path == NULL)
		return (NULL);

	command_len = strlen(command);
	path_len = strlen(path);
	path_copy = (char *)malloc(path_len + 1);

	if (path_copy == NULL)
		return (NULL);

	strcpy(path_copy, path);
	token = strtok_r(path_copy, ":", &saveptr);

	while (token != NULL)
	{
		size_t token_len = strlen(token);

		full_path = (char *)malloc(token_len + 1 + command_len + 1);

		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		token = strtok_r(NULL, ":", &saveptr);
	}
	free(path_copy);
	return (NULL);
}

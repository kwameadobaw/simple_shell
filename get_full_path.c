#include "main.h"
/**
 * get_full_path - Find the full path of an executable in the PATH
 * @command: The command to search for
 * Return: The full path to the executable if found, or NULL if not found or
 * on error.
*/
char *get_full_path(const char *command)
{
	char *path_env = getenv("PATH");
	char *path_env_copy;
	char *token;
	char *full_path;

	if (path_env == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not found\n");
		return (NULL);
	}
	path_env_copy = strdup(path_env);
	if (path_env_copy == NULL)
	{
		perror("Error: Unable to allocate memory");
		return (NULL);
	}
	token = strtok(path_env_copy, PATH_DELIMITER);
	while (token != NULL)
	{
		full_path = (char *)malloc(strlen(token) + strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("Error: Unable to allocate memory");
			free(path_env_copy);
			return (NULL);
		}
		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_env_copy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, PATH_DELIMITER);
	}
	free(path_env_copy);
	fprintf(stderr, "Error: Command not found in PATH: %s\n", command);
	return (NULL);
}

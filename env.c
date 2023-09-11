#include "main.h"
/**
 * set_env - Set or modify an environment variable
 * @variable: The name of the environment variable
 * @value: The value to set for the environment variable
 * Return: 0 on success, -1 on failure
*/
int set_env(const char *variable, const char *value)
{
	char *env_str;

	if (variable == NULL || value == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	env_str = (char *)malloc(strlen(variable) + strlen(value) + 2);

	if (env_str == NULL)
	{
		perror("setenv");
		return (-1);
	}

	sprintf(env_str, "%s=%s", variable, value);

	if (putenv(env_str) != 0)
	{
		perror("setenv");
		free(env_str);
		return (-1);
	}
	free(env_str);

	return (0);
}
/**
 * unset_env - Unset an enviroment variable
 * @variable: The name of the environment variable to unset
 *
 * Return: 0 on success, -1 on failure
*/
int unset_env(const char *variable)
{
	if (variable == NULL)
	{
		fprintf(stderr, "Usage: unsetenv");
		return (-1);
	}

	return (0);
}

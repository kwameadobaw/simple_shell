#include "shell.h"
/**
 * own_env - show current env
 * @args: string containing arguments
 * Return: 1 to show success
 */
int own_env(char **args)
{
	char **env_var = environ;

	while (*env_var)
	{
		size_t len = strlen(*env_var);

		write(STDOUT_FILENO, *env_var, len);
		write(STDOUT_FILENO, "\n", 1);

		env_var++;
	}
	(void)args;

	return (1);
}

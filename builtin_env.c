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
		char *env_str = *env_var;
		size_t len = _strlen(env_str);

		if (len > 0)
		{
			write(STDOUT_FILENO, env_str, len);
			write(STDOUT_FILENO, "\n", 1);
		}

		env_var++;
	}
	(void)args;

	return (0);
}

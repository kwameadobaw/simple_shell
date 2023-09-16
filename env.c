#include "main.h"
/**
 * print_environment - prints current env
 */
void print_environment(void)
{
	char **env_var = environ;

	while (*env_var)
	{
		size_t len = _strlen(*env_var);

		write(STDOUT_FILENO, *env_var, len);
		write(STDOUT_FILENO, "\n", 1);

		env_var++;
	}
}

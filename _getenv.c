#include "main.h"
/**
 * _getenv - Get the value of an environment variable
 * @name: The name of the environment variable to retrieve
 *
 * Return: Pointer to the value of the environment variable or NULL
*/
char *_getenv(const char *name)
{
	int name_length;
	char **env;

	if (name == NULL || environ == NULL)
		return (NULL);

	name_length = _strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, name_length) == 0 
				&& (*env)[name_length] == '=')
		{
			return (*env + name_length +1);
		}
	}

	return (NULL);
}

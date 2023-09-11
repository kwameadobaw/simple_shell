#include "main.h"
/**
 * _setenv - Change or add an environment variable
 * @name: The name of the environment variable
 * @value: The value to set for the environment variable
 * @overwrite: If 1, overwrite the variable if it already exists, if 0 overwite
 *
 * Return: 0 on success, -1 on failure
*/
int _setenv(const char *name, const char *value, int overwrite)
{
	int name_length;
	int value_length, i;

	if (name == NULL || value == NULL)
		return (-1);

	name_length = _strlen(name);
	value_length = _strlen(value);

	if (environ[MAX_ENV_VARS - 1] != NULL)
		return (-1);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, name_length)
				== 0 && environ[i][name_length] == '=')
		{
			if (overwrite)
			{
				_strncpy(environ[i] + name_length + 1,
						value, value_length);
				environ[i][name_length + 1 + value_length]
					= '\0';
				return (0);
			}
			else
			{
				return (0);
			}
		}
	}
	if (i < MAX_ENV_VARS - 1)
	{
		snprintf(environ[i], name_length + value_length + 2,
				"%s=%s", name, value);
		environ[i + 1] = NULL;
		return (0);
	}
	return (-1);
}


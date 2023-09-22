#include "shell.h"
/**
 * _strlen - Get the length of a string
 * @s: Pointer to the string
 * Return: Always 0
 */
int _strlen(const char *s)
{
	const char *p = s;

	while (*p != '\0')
	{
		p++;
	}
	return (p - s);
}

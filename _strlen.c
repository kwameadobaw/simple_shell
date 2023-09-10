#include "main.h"
/**
 * _strlen - Get the length of a string
 * @s: Pointer to the string
 * Return: Always 0
 */
int _strlen(char *s)
{
	char *p = s;

	while (*p != '\0')
	{
		p++;
	}
	return (p - s);
}

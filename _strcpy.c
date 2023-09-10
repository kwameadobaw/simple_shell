#include "main.h"
/**
 * _strcpy - Copy content from src to dest
 * @dest: Pointer to destination variable
 * @src: Pointer to source variable
 * Return: Pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	char *destination = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (destination);
}

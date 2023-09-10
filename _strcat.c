#include "main.h"
/**
 * _strcat - Used to concatenate strings
 *
 * @dest: Destination of string concatenated
 *
 * @src: Source of string to be concatenated
 *
 * Return: Return the value of dest
 */
char *_strcat(char *dest, char *src)
{
	char *dest_pt = dest;

	while (*dest_pt != '\0')
	{
		dest_pt++;
	}
	while (*src != '\0')
	{
		*dest_pt = *src;
		dest_pt++;
		src++;
	}
	*dest_pt = '\0';
	return (dest);
}

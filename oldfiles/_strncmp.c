#include "main.h"
/**
 * _strncmp - compare 2 strings
 * @str1: first string
 * @str2: second string
 * @n:the size
 * Return: always 0
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0)
	{
		if (*str1 == '\0' || *str2 == '\0')
			return (0);

		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		n--;
	}
	return (0);
}

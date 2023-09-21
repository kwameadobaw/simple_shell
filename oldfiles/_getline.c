#include "main.h"
/**
 * my_getline - Read a line of input from the user
 * @input: The input buffer to store the line
 * @max_length: The maximum length of the input buffer
 * Return: The number of characters read, or -1 on error
 */
ssize_t my_getline(char *input, size_t max_length)
{
	static char buffer[MAX_COMMAND_LENGTH];
	static size_t buffer_position;
	static size_t buffer_size;
	size_t i = 0;
	char c;

	while (i < max_length - 1)
	{
		if (buffer_position >= buffer_size)
		{
			buffer_size = read(STDIN_FILENO, buffer, sizeof(buffer));
			if (buffer_size <= 0)
				return (buffer_size);
			buffer_position = 0;
		}
		c = buffer[buffer_position++];
		input[i++] = c;
		if (c == '\n')
			break;
	}
	input[i] = '\0';
	return (i);
}

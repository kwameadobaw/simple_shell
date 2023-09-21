#include "shell.h"
/**
 * read_stream - read a line from the stream
 *
 * Return: pointer that points the the read line
 */
char *read_stream(void)
{
	size_t bufsize = 1024;
	char *line = malloc(bufsize * sizeof(char));
	ssize_t characters_read;

	if (!line)
	{
		fprintf(stderr, "Allocation error in read_stream");
		exit(EXIT_FAILURE);
	}

	characters_read = getline(&line, &bufsize, stdin);

	if (characters_read == -1)
	{
		free(line);
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("Error while reading input");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}

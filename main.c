#include "main.h"
/**
 * main - Entry point for the simple shell program
 * Return: Always 0.
*/
int main(void)
{
	char input[MAX_COMMAND_LENGTH], full_path[MAX_COMMAND_LENGTH];
	size_t input_length;

	while (1)
	{
		printf("simple_shell> ");

		if (!fgets(input, sizeof(input), stdin))
		{
			if (feof(stdin))
			{
				printf("\nGoodbye!\n");
				exit(0);
			}
			else
			{
				perror("Error reading input");
				exit(1);
			}
		}
		input_length = strlen(input);
		if (input_length > 0 && input[input_length -1] == '\n')
		{
			input[input_length - 1] = '\0';
		}
		if (strcmp(input, "") == 0)
		{
			continue;
		}

		if (find_executable_path(input, full_path, sizeof(full_path)))
		{
			execute_command(full_path);
		}
		else
		{
			printf("No such file or directory\n");
		}
	}
	return (0);
		if (strchr(input, ' ') || strncmp(input, "/bin/", 5) != 0)
		{
			printf("No such file or directory\n");
		}
		else
		{
			execute_command(input);
		}
	}
}

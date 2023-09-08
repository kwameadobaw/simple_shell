#include "main.h"
/**
 * execute_command - Execute a command in a child process
 * @input: The command to execute
*/
void execute_command(const char *input)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid < 0)
	{
		perror("Fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		if (system(input) == -1)
		{
			perror("Command execution failed");
			exit(1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			printf("Command execution failed\n");
		}
	}
}
/**
 * print_environment - Print the current environment variables
 *
 * This function prints each environment variable to the standard output.
*/
void print_environment()
{
	extern char **environ;
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
/**
 * main - Entry point for the simple shell program
 * Return: Always 0.
*/
int main(void)
{
	char input[MAX_COMMAND_LENGTH];
	size_t input_length;

	while (1)
	{
		printf("simple_shell> ");

		if (fgets(input, sizeof(input), stdin) == NULL)
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
		if (input_length > 0 && input[input_length - 1] == '\n')
		{
			input[input_length - 1] = '\0';
		}
		if (strcmp(input, "") == 0)
		{
			continue;
		}
		if (strcmp(input, "exit") == 0)
		{
			printf("Goodbye!\n");
			exit(0);
		}
		if (strcmp(input, "env") == 0)
		{
			print_environment();
			continue;
		}

		execute_command(input);
	}
	return (0);
}


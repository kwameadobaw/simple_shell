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
		char *args[4];

		args[0] = "/bin/sh";
		args[1] = "-c";
		args[2] = (char *)input;
		args[3] = NULL;

		if (execvp(args[0], args) == -1)
		{
			perror("Command execution failed");
			exit(1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		
		if (WIFEXITED(status))
		{
			int exit_code = WEXITSTATUS(status);
			if (exit_code != 0)
			{
				printf("No such file or directory\n");
			}
		}
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
		if (strchr(input, ' ') || strncmp(input, "/bin/", 5) != 0)
		{
			printf("No such file or directory\n");
		}
		else
		{
			execute_command(input);
		}
	}

	return (0);
}

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
 * main - entry point
 * Return: Always 0
 */
int main(void)
{
	char input[MAX_COMMAND_LENGTH];
	size_t input_length;

	while (1)
	{
		write(STDOUT_FILENO, "simple_shell> ", 14);
		if (my_getline(input, sizeof(input)) == -1)
		{
			perror("Error reading input");
			exit(1);
		}
		input_length = _strlen(input);

		if (input_length > 0 && input[input_length - 1] == '\n')
		{
			input[input_length - 1] = '\0';
		}
		if (_strcmp(input, "") == 0)
		{
			continue;
		}
		if (_strcmp(input, "exit") == 0)
		{
			write(STDOUT_FILENO, "Goodbye!\n", 9);
			exit(0);
		}
		if (_strncmp(input, "exit ", 5) == 0)
		{
			int status = _atoi(input + 5);

			exit(status);
		}
		else
		{
			execute_command(input);
		}
	}
	return (0);
}

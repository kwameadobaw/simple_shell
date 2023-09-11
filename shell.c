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
		char *args[MAX_ARGUMENTS];
		char *token = strtok((char *)input, " ");
		int i = 0;

		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		if (execvp(args[0], args) == -1)
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
			write(STDOUT_FILENO, "Command execution failed\n", 26);
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
		if (strncmp(input, "setenv ", 7) == 0)
		{
			const chat *cmd = input + 7;
			char *variable = strtok((char *)cmd, " ");
			char *value = strtok(NULL, " ");

			if (variable != NULL && value != NULL)
			{
				int result = setenv(variable, value, 1);
				if (result == 0)
				{
					write(STDOUT_FILENO, "Env set.\n" 9);
				}
				else
				{
					fprintf(stderr, "setenv: failed setenv\n");
				}
			}
			else
			{
				fprintf(stderr, "setenv: invalid arguments\n");
			}
		}
		else if (strncmp(input, "unsetenv ", 9) == 0)
		{
			const char *cmd = input + 9;
			char *variable = strtok((char *)cmd, " ");

			if (variable != NULL)
			{
				int result = _unsetenv(variable);
				if (result == 0)
				{
					write(STDOUT_FILENO, "unset\n", 6);
				}
				else
				{
					fprintf(stderr, "unsetenv:
						       	failed unset\n");
				}
			}
			else
			{
				fprintf(stderr, "unsetenv: 
						invalid arguments\n");
			}
		}
		else if (strncmp(input, "cd ", 3) == 0)
		{
			const char *cmd = input + 3;
			int success = change_directory(cmd, prev_dir, environ);
			if (success)
			{
				free(prev_dir);
				prev_dir = getcwd(NULL, 0);
			}
		}
		else if (strncmp(input, "getenv ", 7) == 0)
		{
			const char *cmd = input + 7;
			char *value = _getenv(cmd);
			if (value != NULL)
			{
				write(STDOUT_FILENO, cmd, strlen(cmd));
				write(STDOUT_FILENO, "=", 1);
				write(STDOUT_FILENO, value, strlen(value));
				write(STDOUT_FILENO, "\n", 1);
			}
			else
			{
				write(STDOUT_FILENO, "PATH absence\n", 13);
			}
		}
		else
		{
			execute_command(input);
		}
	}
	return (0);
}

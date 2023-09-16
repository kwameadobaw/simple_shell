#include "main.h"
/**
 * execute_command - Execute a command in a child process
 * @input: The command to execute
*/
void execute_command(const char * const args[])
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
		if (strchr(args[0], '/') == NULL)
		{
			char *full_path = get_full_path(args[0]);

			if (full_path == NULL)
			{
				fprintf(stderr, "Command not found: %s\n", args[0]);
				exit(1);
			}
			if (execve(full_path, (char * const *)args, environ) == -1)
			{
				perror("Command execution failed");
				exit(1);
			}
		}
		else
		{
			if (execve(args[0], (char * const *)args, environ) == -1)
			{
				perror("Command execution failed");
				exit(1);
			}
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
 * tokenize_input - Tokenize the input string based on spaces
 * @input: The input string to tokenize
 * @tokens: An array to store the tokens
 * @max_tokens: Maximum number of tokens to extract
 * Return: TYhe number of tokens extracted
*/
int tokenize_input(char *input, char *tokens[], int max_tokens)
{
	char *token;
	int token_count = 0;

	token = strtok(input, " ");
	while (token != NULL && token_count < max_tokens)
	{
		tokens[token_count++] = token;
		token = strtok(NULL, " ");
	}
	return (token_count);
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
		else if (_strncmp(input, "setenv ", 7) == 0)
		{
			char *args[3];
			int token_count = tokenize_input(input, args, 3);
		
			if (token_count != 3)
			{
				write(STDOUT_FILENO, "Usage: setenv VARIABLE VALUE\n", 29);
				continue;
			}
			if (setenv(args[1], args[2], 1) != 0)
			{
				perror("setenv");
			}
		}
		else if (_strncmp(input, "unsetenv ", 9) == 0)
		{
			char *args[2];
			int token_count = tokenize_input(input, args, 2);
		
			if (token_count != 2)
			{
				write(STDOUT_FILENO, "Usage: unsetenv VARIABLE\n", 25);
				continue;
			}
			if (unsetenv(args[1]) != 0)
			{
				perror("unsetenv");
			}
					
		}
		else
		{
			char *args[MAX_ARGUMENTS];
			int token_count = tokenize_input(input, args, MAX_ARGUMENTS);
		
			if (token_count == 0)
			{
				continue;
			}
			execute_command((const char * const *)args);
		}
	}
	return (0);
}

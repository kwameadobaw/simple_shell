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
 * handle_command_with_args - Handle command lines with arguments
 * @input: The command to execute with arguments
*/
void handle_command_with_args(const char *input)
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
		char *args[MAX_COMMAND_LENGTH];
		char *token = strtok((char *)input, " ");
		int arg_count = 0;

		while (token != NULL && arg_count < MAX_COMMAND_LENGTH - 1)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

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
				printf("No such file or directory\n");
		}
	}
}

#include "shell.h"
/**
 * execute_args - map if command is a builtin or a process
 * @args: command and its flags
 *
 * Return: 1 on sucess, 0 otherwise
 */
int execute_args(char **args)
{
	char *builtin_func_list[] = {
	"cd",
	"env",
	"exit",
	"setenv",
	"unsetenv"
	};

	int (*builtin_func[])(char **) = {
	&own_cd,
	&own_env,
	&own_exit,
	&own_setenv,
	&own_unsetenv
	};

	size_t i = 0;

	if (args[0] == NULL)
		return (-1);

	for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)
	{
		if (_strcmp(args[0], builtin_func_list[i]) == 0)
		{
			if (_strcmp(args[0], "exit") == 0)
			{
				return (own_exit(args));
			}
			else if (_strcmp(args[0], "env") == 0)
			{
				return (own_env(args));
			}
			else
			{
				return ((*builtin_func[i])(args));
			}
		}
	}

	return (new_process(args));
}
/**
 * new_process - create a new process
 * @args: array of strings that contains the command and its flags
 *
 * Return: 1 if success, 0 otherwise.
 */
int new_process(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			perror("error in new_process: child process");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("error in new_process: forking");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (-1);
}

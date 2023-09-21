#include "main.h"
/**
 * handle_exit - Handle the "exit" command with an optional status code
 * @input: The input string containing the status code (if provided)
 *
 * This function handles the "exit" command in a simple shell. If the input
 * sting is "exit", it exists the shell with a status code of 0. If the input
 * string is "exit <status>", it converts the status string to an integer and
 * exists the shell with the specified status code.
*/
void handle_exit(char **input)
{
	int status = 0;

	status = atoi(input[1]);

	exit(status);
}

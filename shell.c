#include "main.h"
int main(void)
{
    char input[MAX_COMMAND_LENGTH];

    while (1)
    {
        printf("simple_shell> ");

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            if (feof(stdin))
            {
                printf("\nGoodbye!\n");
                exit(0); // End of file (Ctrl+D) was reached
            }
            else
            {
                perror("Error reading input");
                exit(1);
            }
        }

        // Remove newline character at the end
        size_t input_length = strlen(input);
        if (input_length > 0 && input[input_length - 1] == '\n')
        {
            input[input_length - 1] = '\0';
        }

        if (strcmp(input, "") == 0)
        {
            continue; // Empty input, prompt again
        }

        char *command = strtok(input, " ");
        char *arguments = strtok(NULL, " ");

        pid_t pid = fork(); // Create a child process

        if (pid < 0)
        {
            perror("Fork failed");
            exit(1);
        }
        else if (pid == 0)
        {
            // Child process
            if (execlp(command, command, arguments, NULL) == -1)
            {
                perror("Command not found");
                exit(1);
            }
        }
        else
        {
            // Parent process
            int status;
            waitpid(pid, &status, 0);

            if (WIFEXITED(status))
            {
                int exit_code = WEXITSTATUS(status);
                if (exit_code != 0)
                {
                    printf("simple_shell: %s: exited with status %d\n", command, exit_code);
                }
            }
        }
    }

    return (0);
}

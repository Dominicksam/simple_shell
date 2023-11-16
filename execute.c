#include "shell.h"

/**
 * execute_command - Execute a shell command.
 * @command: The command to be executed.
 * return: 0 on success
 * This function creates a child process using `fork()` and attempts to execute
 * the specified command in that child process using `execve()`. The parent
 * process waits for the child to complete. If error, an error message
 * is printed using `perror()` and the program exits with an error status.
 */
int execute_command(const char *command)
{
	char *env_path = getenv("PATH");
	char *token;
	char *args[2];
	pid_t child_pid;
	token = strtok(env_path, ":");

	while (token != NULL)
	{
		char *full_path = malloc(strlen(token) + strlen(command) + 2);

		sprintf(full_path, "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
		{
			args[0] = full_path;
			args[1] = NULL;

			child_pid = fork();
			if (child_pid == -1)
			{
				perror("fork");
				free(full_path);
				exit(EXIT_FAILURE);
			}
			else if (child_pid == 0)
			{
				if (execve(full_path, args, NULL) == -1)
				{
					perror("execve");
					free(full_path);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				wait(NULL);
				free(full_path);
				return (1);
			}
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	fprintf(stderr, "%s: command not found\n", command);
	return (0);
}


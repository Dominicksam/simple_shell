#include "shell.h"

/**
 * execute_command - Execute a shell command.
 * @command: The command to be executed.
 *
 * This function creates a child process using `fork()` and attempts to execute
 * the specified command in that child process using `execve()`. The parent
 * process waits for the child to complete. If error, an error message
 * is printed using `perror()` and the program exits with an error status.
 */

void execute_command(const char *command)
{
	pid_t child_pid = fork();
	char *args[2];
	char *envp[] = { NULL };

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		args[0] = (char *)command;
		args[1] = NULL;


		if (execve(command, args, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}


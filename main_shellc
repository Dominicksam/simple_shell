#include "shell.h"
#include <stdbool.h>

/**
 * main - The entry point of the program.
 * @argv: argument variable
 * This function contains the main loop for your shell. It repeatedly
 * displays a prompt, reads a command, and executes it.
 * @argc: argument count
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	char command[150];
	FILE *input = stdin;

	while (true)
	{
		prompt_display();
		read_command(command, sizeof(command), input);
		execute_command(command);
	}

	if (argc > 1)
	{
		input = fopen(argv[1], "r");
		if (input == NULL)
		{
			fprintf(stderr, "Error opening the file.\n");
			exit(EXIT_FAILURE);
		}
		if (input != stdin)
		{
			fclose(input);
		}
	}
	return (0);
}

/**
 * prompt_display - Display the shell prompt.
 *
 * This function displays the prompt for the shell, typically indicating
 * that the user can input a command.
 */
void prompt_display(void)
{
	write(1, "DM_shell$ ", 10);
}


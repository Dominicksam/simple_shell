#include "main.h"

/**
 * main - Simple shell program
 *
 * Description: Reads user input, and handles built-in commands.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *input = NULL;
	size_t size = 0;

	while (1)
	{
		write_str("$ ");
		if (getline(&input, &size, stdin) == -1)
		{
			free(input);
			break;
		}
		char *input_dup = _strdup(input);
		char *tok = strtok(input_dup, " \t\r\n");

		if (_strcmp(tok, "env") == 0)
		{
			env();
			free(input_dup);
			continue;
		}
		if (_strcmp(tok, "exit") == 0)
		{
			free(input);
			free(input_dup);
			break;
		}
		if (*tok == '#' || no_input(input_dup) == 0)
		{
			free(input_dup);
			continue;
		}
		if (handle_cd(input, input_dup) == 0)
		{
			free(input_dup);
			continue;
		}

		free(input_dup);
	}
	return (0);
}

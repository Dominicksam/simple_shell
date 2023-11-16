#include "shell.h"

/**
 * read_command - Read a command from the user.
 * @command: The buffer to store the command.
 * @size: The size of the buffer.
 * @input: standard input from main function
 * This function reads a command from the standard input (stdin) and stores
 * it in the provided buffer. It handles potential errors during input.
 */
void read_command(char *command, size_t size, FILE *input)
{
	if (fgets(command, size, stdin) == NULL)

	{
		if (feof(stdin))
		{
			if (input == stdin)
			{
				dm_print("\n");
			}
			exit(EXIT_SUCCESS);
		}
		else
		{
			fprintf(stderr, "Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	else if (ferror(input))
	{
		perror("Error while reading input");
		exit(EXIT_FAILURE);
	}

	command[strcspn(command, "\n")] = '\0';
}

/**
 * interactive - Checks if the shell is running in interactive mode.
 * @info: Pointer to the info_t structure.
 *
 * Return: 1 if interactive, 0 otherwise.
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - Checks if a character is a delimiter.
 * @c: The character to check.
 * @delim: The string of delimiters.
 *
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */

int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - Checks if a character is alphabetic.
 * @c: The character to check.
 *
 * Return: 1 if the character is alphabetic, 0 otherwise.
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

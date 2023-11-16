#include "main.h"

/**
 * main - The main function.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *input = NULL;
	size_t size = 0;
	int isterminal = 0;
	char *input_dup2, *input_dup3, *tok, *input_dup;

	while (1)
	{
		if (isatty(isterminal) != 0)
			write_str("$ ");
		if (getline(&input, &size, stdin) == -1)
		{
			free(input);
			break;
		}
		input_dup2 = _strdup(input);
		input_dup3 = _strdup(input);
		tok = strtok(input_dup2, " \t\r");
		if (_strcmp(tok, "exit\n") == 0)
		{
			free(input);
			free(input_dup3);
			free(input_dup2);
			_exit_status(input_dup3);
			break;
		}
		if (*tok == '#' || no_input(input) == 0)
		{
			free(input_dup3);
			continue;
		}
		input_dup = _strdup(input);
		if (handle_cd(input_dup, input_dup2) == 0)
			continue;
		if (isterminal != 0)
			break;
		continue;
	}
	return (0);
}

/**
 * handle_cd - Handles the command input.
 * @input_dup: duplicates of the input.
 * @input_dup2: duplicates of the input.
 *
 * Return: 0 on success, 1 on failure.
 */
int handle_cd(char *input_dup, char *input_dup2)
{
	struct stat buffer;
	char *userinput = _strdup(input_dup);

	if (environ_cmd(userinput) == 0)
	{
		free(input_dup2);
		free(input_dup);
		return (0);
	}
	if (compare_path(input_dup2) == 0)
	{
		free(input_dup);
		return (0);
	}
	if (stat(input_dup, &buffer) == -1)
	{
		free(input_dup);
		perror("./hsh");
	}
	return (1);
}

/**
 * _strcmp - Compares two strings.
 * @str1: The first string.
 * @str2: The second string.
 *
 * Return: 0 if equal, 1 otherwise.
 */
unsigned int _strcmp(char *str1, char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return (1);
		}
		str1++;
		str2++;
	}
	return (0);
}

/**
 * _strlen - Calculates the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
unsigned int _strlen(const char *str)
{
	unsigned int count = 0;

	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

/**
 * write_str - Writes a string to standard output.
 * @str: The string to write.
 *
 * Return: Always 0.
 */
int write_str(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
	return (0);
}

/**
 * no_input - Checks if there is any input.
 * @input: The input string.
 *
 * Return: 0 if no input, 1 otherwise.
 */
int no_input(char *input)
{
	int count = 0;
	char *token = strtok(input, " \n\r\t");

	for (; token != NULL;)
	{
		count++;
		token = strtok(NULL, " \n\r\t");
	}
	count++;
	free(input);
	if (count == 1)
	{
		return (0);
	}
	return (1);
}

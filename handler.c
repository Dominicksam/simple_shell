#include "main.h"

/**
 * handle_cd - Handles the 'cd' command.
 * @input: Original user input (unused).
 * @input_dup: Duplicate of user input for tokenization.
 *
 * Return: 0 on success, 1 on failure.
 */
int handle_cd(char *input, char *input_dup)
{
	(void)input;

	char *src = "/bin/";
	char *dup = _strdup(input_dup);
	char *token = strtok(dup, " \n\r\t");
	char *input_path = _strcat(src, token);

	if (stat(input_path, &buffer) != -1)
	{
		_fork(input, token, 0);
		free(input_dup);
		free(dup);
		free(input_path);
		return (0);
	}

	free(dup);
	free(input_path);
	return (1);
}

/**
 * _fork - Creates a child process to execute a command.
 * @input: Command to execute.
 * @token: Tokenized command arguments.
 * @arg_size: Size of command arguments.
 *
 * Return: 0 on success, 1 on failure.
 */
int _fork(char *input, char *token, int arg_size)
{
	pid_t pid = 0;
	int i = 0;
	char *argv[100];
	(void)arg_size;

	argv[i] = token;
	i++;
	token = strtok(NULL, " \n\t\r");

	for (; token != NULL; i++)
	{
		if (*token == '#')
			break;
		argv[i] = token;
		token = strtok(NULL, " \n\t\r");
	}

	argv[i] = NULL;
	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		free(input);
		return (1);
	}

	if (pid == 0)
	{
		if (execve(input, argv, NULL) == -1)
		{
			free(input);
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}

	wait(NULL);
	free(input);
	return (0);
}

/**
 * token_num - Counts the number of tokens in a string.
 * @str: Input string.
 *
 * Return: Number of tokens.
 */
int token_num(char *str)
{
	int i;
	int size = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] != '\0'))
		{
			size++;
		}
		continue;
	}

	return (size);
}

/**
 * _strcat - Concatenates two strings.
 * @src: Source string.
 * @dest: Destination string.
 *
 * Return: Newly allocated concatenated string.
 */
char *_strcat(char *src, char *dest)
{
	char *new_str = malloc(sizeof(char) * (_strlen(src) + _strlen(dest) + 1));
	int i, j;

	for (i = 0, j = 0;; i++, j++)
	{
		if (src[j] == '\0')
		{
			j = 0;
			new_str[i] = dest[j];
			i++;
			j++;

			for (; dest[j] != '\0'; i++, j++)
			{
				new_str[i] = dest[j];
			}

			new_str[i] = '\0';
			break;
		}
		new_str[i] = src[j];
	}

	return (new_str);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

static char input_buffer[BUFFER_SIZE];
static size_t buffer_index;
static size_t buffer_size;

/**
 * read_input - Read characters into the buffer.
 *
 * Return: ssize_t - The number of bytes read, or -1 on error.
 */
static ssize_t read_input(void)
{
	buffer_size = read(STDIN_FILENO, input_buffer, BUFFER_SIZE);
	buffer_index = 0;

	if (buffer_size < 0)
	{
		perror("read");
		return (-1);
	}

	return (buffer_size);
}

/**
 * my_getline - Get a line from standard input.
 *
 * Return: char* - A dynamically allocated string containing the line,
 *                or NULL on EOF or error.
 */
char *my_getline(void)
{
	char *line = NULL;
	size_t line_size = 0;

	while (1)
	{
		if (buffer_index >= buffer_size)
		{
			if (read_input() <= 0)
			{
				free(line);
				return (NULL);
			}
		}

		if (line_size <= 0 || line[line_size - 1] == '\0')
		{
			line_size += BUFFER_SIZE;
			line = realloc(line, line_size);

			if (line == NULL)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}

		while (buffer_index < buffer_size && input_buffer[buffer_index] != '\n')
		{
			line[line_size - BUFFER_SIZE + buffer_index] = input_buffer[buffer_index];
			buffer_index++;
		}

		if (buffer_index < buffer_size && input_buffer[buffer_index] == '\n')
		{
			line[line_size - BUFFER_SIZE + buffer_index] = '\0';
			buffer_index++;
			return (line);
		}
	}
}

int main(void)
{
	char *line;

	while ((line = my_getline()) != NULL)
	{
		printf("Line: %s\n", line);
		free(line);
	}

	return (0);
}


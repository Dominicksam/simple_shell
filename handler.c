#include "main.h"

int input_cd(char *str)
{
	char *src = "/bin/";
	char *token = strtok(str, " \n\r\t");
	char *dup = _strdup(token);
	char *input = _strcat(src, dup);
	struct stat buffer;
	int signal;
	free(dup);

	if (stat(input, &buffer) != -1)
	{
		signal = _fork(input, token, 0);
		free(input);
		free(str);
		return signal;
	}
	free(input);
	free(str);
	return 1;
}
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
	return new_str;
}

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
	return size;
}

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
		return 1;
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
	return 0;
}


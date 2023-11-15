#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * my_setenv - Set or update an environment variable
 * @name: The name of the environment variable
 * @value: The value to set for the environment variable
 * @overwrite: Flag to overwrite if the variable already exists
 *
 * Return: 0 on success, -1 on failure
 */
int my_setenv(const char *name, const char *value, int overwrite)
{
	char *env_var;

	if (name == NULL || value == NULL)
	{
		fprintf(stderr, "setenv: Invalid arguments\n");
		return (-1);
	}

	if (getenv(name) != NULL && !overwrite)
	{
		fprintf(stderr, "setenv: Variable %s already exists cannet overide\n", name);
		return (-1);
	}

	env_var = malloc(strlen(name) + strlen(value) + 2);
	if (env_var == NULL)
	{
		perror("Error");
		return (-1);
	}

	sprintf(env_var, "%s=%s", name, value);

	if (putenv(env_var) != 0)
	{
		perror("Error");
		free(env_var);
		return (-1);
	}

	return (0);
}

/**
 * my_unsetenv - Unset an environment variable
 * @name: The name of the environment variable to unset
 *
 * Return: 0 on success, -1 on failure
 */
int my_unsetenv(const char *name)
{
	if (name == NULL)
	{
		fprintf(stderr, "unsetenv: Invalid argument\n");
		return (-1);
	}

	if (unsetenv(name) != 0)
	{
		perror("Error");
		return (-1);
	}

	return (0);
}


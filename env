#include "main.h"

/**
* _env1 - Set an environment variable
* @env_name: The name of the variable
* @env_value: The value to set
*
* Return: (1) if successful, (0) otherwise
*/

int _env1(char *env_name, char *env_value)
{
	int i;
	for (i = 0 ; environ[i] != NULL; i++)
	{
		char *token = strdup(environ[i]);
		char *tok = strtok(token, "=");
		if (_strcmp(env_name, tok) == 0)
		{
			env_name = _strcat(env_name, "=");
			env_value = _strcat(env_name, env_value);
			environ[i] = env_value;
			free(env_name);
			free(token);
			token = NULL;
			return (1);
		}
		free(token);
		token = NULL;
	}
	env_name = _strcat(env_name, "=");
	env_value = _strcat(env_name, env_value);
	environ[i] = env_value;
	environ[i + 1] = NULL;
	free(env_name);
	return (0);
}

/**
* _unenv - Unset an environment variable
* @env_name: The name of the variable to unenv
*
* Return: (0) if successful, (1) otherwise
*/
int _unenv(char *env_name)
{
	int i;
	for (i = 0; environ[i] != NULL; i++)
	{
		char *token = _strdup(environ[i]);
		char *tok = strtok(token, "=");
		if (_strcmp(env_name, tok) == 0)
		{
			free(token);
			for (; environ[i] != NULL; i++)
			{
				environ[i] = environ[i + 1];
			}
			return (0);
		}
		free(token);
	}
	return (1);
}

/**
* env - Print the environment variables
*
* Return: Always (0)
*/

int env(void)
{
	int i;
	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
	return (0);
}

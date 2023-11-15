#include "main.h"

int main(void)
{
	char *input = NULL;
	size_t size = 0;
	int isterminal = 0;
	char *input_dup, *input_dup2, *tok, *input_dup3;

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
	
	tok = strtok(input_dup2, " \t\r\n");
	if (_strcmp(tok, "exit") == 0) 
	{
		free(input);
		free(input_dup3);
		free(input_dup2);
		_exit_status(input_dup3);
	}
	if (*tok == '#' || no_input(input_dup2) == 0)
	{
		free(input_dup3);
		continue;
	}
	
	input_dup = _strdup(input);
	
	if (handle_cd(input_dup3, input_dup) == 0) 
	{
		free(input_dup);
		continue;
	}
	if (isterminal != 0)
	break;
	continue;
	}
	return (0);
}	

#include "main.h"


/**
* _strcat - Concatenates two strings.
* @src: The source string.
* @dest: The destination string.
*
* Return: A pointer to the concatenated string.
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

/**
* token_num - Counts the number of tokens in a string.
* @str: The input string.
*
* Return: The number of tokens.
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

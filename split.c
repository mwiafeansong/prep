#include "main.h"

/**
 * is_delim - determines if a character is a delimiter specified
 * @c: character
 * @delim: delimiter(s)
 *
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	int i;

	for (i = 0; delim[i] != '\0'; i++)
	{
		if (c == delim[i])
			return (1);
	}

	return (0);
}

/**
 * _strtok - divides a string into strings
 * @str: string to divide
 * @delim: string of delimiter(s)
 *
 * Return: first string after division
 */
char *_strtok(char *str, char *delim)
{
	static char *input;
	char *token;

	if (!str)
		str = input;
	if (!str)
		return (NULL);

	while (1)
	{
		if (is_delim(*str, delim))
		{
			str++;
			continue;
		}
		if (*str == '\0')
		{
			return (NULL);
		}
		break;
	}

	token = str;
	while (1)
	{
		if (*str == '\0')
		{
			input = str;
			return (token);
		}
		if (is_delim(*str, delim))
		{
			*str = '\0';
			input = str + 1;
			return (token);
		}
		str++;
	}
}

/**
 * split_string - splits a string into multiple strings
 * @str: string to be split
 *
 * Return: array of strings
 */
char **split_string(char *str)
{
	char **tokens;
	char *token;
	int i, old_bufsize, bufsize = TOK_BUFSIZE;

	tokens = malloc(bufsize * sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	token = _strtok(str, TOK_DELIMS);
	for (i = 0; token != NULL; i++)
	{
		tokens[i] = token;
		if (i >= bufsize)
		{
			old_bufsize = bufsize;
			bufsize += TOK_BUFSIZE;
			tokens = grid_realloc(tokens, old_bufsize, bufsize);
			if (tokens == NULL)
				return (NULL);
		}
		token = _strtok(NULL, TOK_DELIMS);
	}
	tokens[i] = NULL;

	return (tokens);
}


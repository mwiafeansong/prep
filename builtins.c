#include "main.h"

/**
 * print_env - prints environment variables
 * @av: user input strings
 *
 * Return: 1
 */
int print_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		_puts(environ[i]);

	return (1);
}

/**
 * exit_shell - exits the shell
 * @av: user input strings
 *
 * Return: 1
 */
int exit_shell(void)
{
	exit(0);
}

/**
 * builtincheck - checks for builtins
 * @av: user input strings
 * @line: string user entered
 *
 * Return: 1 (if env entered) or 0
 */
int builtincheck(char **av, char *line)
{
	int i;

	if (_strcmp(av[0], "env") == 0)
	{
		print_env();
		for (i = 0; av[i] != NULL; i++)
			free(av[i]);
		free(av);
		free(line);

		return (1);
	}
	else if (_strcmp(av[0], "exit") == 0)
	{
		for (i = 0; av[i] != NULL; i++)
			free(av[i]);
		free(av);
		free(line);
		exit_shell();
	}

	return (0);
}

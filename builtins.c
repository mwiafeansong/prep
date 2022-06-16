#include "main.h"

/**
 * print_env - prints environment variables
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
 * builtincheck - checks for builtins
 * @av: user input strings
 * @line: string user entered
 * @pathdirs: directories in path
 * @exitstatus: exitstatus of execve
 *
 * Return: 1 (if env entered) or 0
 */
int builtincheck(char **av, char *line, char **pathdirs, int exitstatus)
{
	if (_strcmp(av[0], "exit") == 0)
	{
		free(av);
		free(line);
		free(pathdirs);
		exit(exitstatus);
	}
	else if (_strcmp(av[0], "env") == 0)
	{
		print_env();
		free(av);
		free(line);

		return (1);
	}
	else
	{
		return (0);
	}
}

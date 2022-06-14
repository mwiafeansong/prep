#include "main.h"

/**
 * prompt - writes prompt to terminal
 *
 * Return: None
 */
void prompt(void)
{
	char *prompt = "$ ";

	if (isatty(STDIN_FILENO) == 1)
	{
		if (write(STDOUT_FILENO, prompt, 2) == -1)
			exit(0);
	}
}

/**
 * read_line - gets user input
 *
 * Return: the user's input
 */
char *read_line(void)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t nread;
	int i;

	nread = getline(&line, &n, stdin);
	if (nread == -1)
	{
		free(line);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}

	if (line[nread - 1] == '\n' || line[nread - 1] == '\t')
		line[nread - 1] = '\0';

	for (i = 0; line[i]; i++)
	{
		if (line[i] == '#' && line[i - 1] == ' ')
		{
			line[i] = '\0';
			break;
		}
	}

	return (line);
}

/**
 * fullpath - gets full path of user input
 * @av: user input strings
 *
 * Return: full path
 */
char *fullpath(char **av, char **pathdirs)
{
	char *concatstr, *fullpath;
	int i, fullpathflag = 0;
	struct stat st;

	for (i = 0; pathdirs[i] != NULL; i++)
	{
		concatstr = _concatpath(pathdirs[i], av[0]);
		if (stat(concatstr, &st) == 0)
		{
			fullpath = concatstr;
			fullpathflag = 1;
			break;
		}
	}

	if (fullpathflag == 0)
		fullpath = av[0];

	free(pathdirs);

	if (stat(fullpath, &st) != 0)
		return (NULL);

	return (fullpath);
}

/**
 * _launch - calls execve
 * @av: user input strings
 * @line: user input
 * @fullpath: full path of command entered by user
 *
 * Return: 1 (on success) 0 (on failure)
 */
int _launch(char **av, char *line, char *fullpath)
{
	pid_t child_pid;
	int i, status, exitstatus;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (0);
	}
	else if (child_pid == 0)
	{
		if (execve(av[0], av, NULL) == -1)
			perror("Error");
		for (i = 0; av[i] != NULL; i++)
			free(av[i]);
		free(av);
		free(line);
		exit(127);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			exitstatus = WEXITSTATUS(status);
		for (i = 0; av[i] != NULL; i++)
			free(av[i]);
		free(av);
		free(line);
	}

	return (1);
}

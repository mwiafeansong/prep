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
 * @pathdirs: path directories
 *
 * Return: full path
 */
char *fullpath(char **av, char **pathdirs)
{
	char *concatstr, *fullpath;
	int i, fullpathflag = 0;
	struct stat st;
	struct stat st2;

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

	if (stat(fullpath, &st2) != 0)
		return (NULL);

	return (fullpath);
}

/**
 * _launch - calls execve
 * @av: user input strings
 * @fullpath: full path of command entered by user
 *
 * Return: 1 (on success) 0 (on failure)
 */
int _launch(char **av, char *fullpath)
{
	pid_t child_pid;
	int status, exitstatus;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		exit(1);
	}
	else if (child_pid == 0)
	{
		if (execve(fullpath, av, NULL) == -1)
			perror(av[0]);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			exitstatus = WEXITSTATUS(status);
	}

	return (exitstatus);
}

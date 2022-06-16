#include "main.h"

/**
 * main - implements a shell
 *
 * Return: 0 (Always success)
 */

int main(void)
{
	char **av, **pathdirs;
	char *line, *fullpathstr, *path, *pathval;
	int exitstatus = 0;

	signal(SIGINT, SIG_IGN);
	path = getfullenv("PATH");
	pathval = _getenv(path);
	pathdirs = getpathdirs(pathval);

	while (1)
	{
		prompt();
		line = read_line();
		av = split_string(line);
		if (av == NULL)
		{
			free(line);
			continue;
		}

		fullpathstr = fullpath(av, pathdirs);
		if (fullpathstr == NULL)
		{
			perror(av[0]);
			free(av);
			free(line);
			continue;
		}

		if (builtincheck(av, line, pathdirs, exitstatus) == 1)
			continue;
		exitstatus = _launch(av, fullpathstr);
		free(av);
		free(line);
	}

	free(pathdirs);

	return (0);
}

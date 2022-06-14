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

	signal(SIGINT, SIG_IGN);

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
		path = getfullenv("PATH");
		pathval = _getenv(path);
		pathdirs = getpathdirs(pathval);
		fullpathstr = fullpath(av, pathdirs);

		if (fullpathstr == NULL)
		{
			free(av);
			free(line);
			continue;
		}

		if (builtincheck(av, line) == 1)
			continue;
		_launch(av, line, fullpathstr);
	}

	return (0);
}

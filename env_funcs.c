#include "main.h"

/**
 * getfullenv - gets environment variable and its value
 * @var_name: the environment variable
 *
 * Return: env variable and its value
 */
char *getfullenv(char *var_name)
{
	int i, j;
	char *envi;

	if (var_name)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			for (j = 0; environ[i][j] != '=' && var_name[j]; j++)
			{
				if (environ[i][j] != var_name[j])
					break;
			}
			if (j == _strlen(var_name))
			{
				envi = environ[i];
			}
		}
	}

	return (envi);
}

/**
 * _getenv - gets the value of an environment variable
 * @name: name of environment variable
 *
 * Return: value of environment variable
 */
char *_getenv(char *name)
{
	char **env_split;
	char *env_val1, *env_val2;
	int i;

	env_split = malloc(TOK_BUFSIZE * sizeof(char *));
	if (env_split == NULL)
		return (NULL);
	env_val1 = _strtok(name, "=");

	for (i = 0; env_val1 != NULL; i++)
	{
		env_split[i] = env_val1;
		env_val1 = _strtok(NULL, "=");
	}
	env_val2 = env_split[1];

	free(env_split);

	return (env_val2);
}

/**
 * getpathdirs - get directories in PATH
 * @path_val: value of PATH
 *
 * Return: array of directories in PATH
 */
char **getpathdirs(char *path_val)
{
	char **pathdirs;
	char *dir;
	int i;

	pathdirs = malloc(TOK_BUFSIZE * sizeof(char *));
	if (pathdirs == NULL)
		return (NULL);

	dir = _strtok(path_val, ":");
	for (i = 0; dir != NULL; i++)
	{
		pathdirs[i] = dir;
		dir = _strtok(NULL, ":");
	}
	pathdirs[i] = NULL;

	return (pathdirs);
}

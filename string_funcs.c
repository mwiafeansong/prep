#include "main.h"

/**
 * _strlen - finds the length of a string
 * @s: the string
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int i, sum = 0;

	for (i = 0; s[i] != '\0'; i++)
		sum++;

	return (sum);
}

/**
 * _strcat - concatenates two strings
 * @dest: string to add to
 * @src: source string
 *
 * Return: new dest string
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int len_dest;

	len_dest = _strlen(dest);

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[len_dest] = src[i];
		len_dest++;
	}
	dest[len_dest] = '\0';

	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 *
 * Return: duplicated string
 */
char *_strdup(char *str)
{
	char *dest;
	int i, len;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);

	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		dest[i] = str[i];
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcmp - compare two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 (if same), another integer if not same
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	return (0);
}

/**
 * _concatpath - increases space for s1 and concatenates with s2
 * @pathdir: first string
 * @str: second string
 *
 * Return: concatenated path
 */
char *_concatpath(char *pathdir, char *str)
{
	int i, len_dir, len_str, tot_len, len_concatstr;
	char *concatstr;

	len_dir = _strlen(pathdir);
	len_str = _strlen(str);
	tot_len = len_dir + len_str + 2;

	concatstr = malloc(tot_len * sizeof(char));
	if (concatstr == NULL)
		return (NULL);

	_memcpy(concatstr, pathdir, tot_len);
	len_concatstr = _strlen(concatstr);
	concatstr[len_concatstr] = '/';
	len_concatstr++;

	for (i = 0; str[i] != '\0'; i++)
		concatstr[len_concatstr + i] = str[i];
	concatstr[len_concatstr + i] = '\0';

	return (concatstr);
}

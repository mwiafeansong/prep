#include "main.h"

/**
 * _putchar - prints a character
 * @c: character to print
 *
 * Return: return value of write system call
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string
 * @s: string to print
 *
 * Return: None
 */
void _puts(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
	_putchar('\n');
}

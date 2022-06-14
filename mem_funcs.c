#include "main.h"

/**
 * _memcpy - copies old memory into new memory space
 * @newptr: new memory space
 * @oldptr: old memory with stored data
 * @size: size of new memory block
 *
 * Return: None
 */
void _memcpy(void *newptr, const void *oldptr, unsigned int size)
{
	char *old_ptr = (char *)oldptr;
	char *new_ptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
	{
		new_ptr[i] = old_ptr[i];
	}
}

/**
 * _realloc - reallocates new memory for stored data
 * @oldptr: old memory block with data
 * @oldsize: size of old memory block
 * @newsize: size of new memory block
 *
 * Return: None
 */
void *_realloc(void *oldptr, unsigned int oldsize, unsigned int newsize)
{
	void *newptr;

	if (oldptr == NULL)
	{
		return (malloc(newsize));
	}
	if (newsize == 0)
	{
		free(oldptr);
		return (NULL);
	}
	if (newsize == oldsize)
	{
		return (oldptr);
	}

	newptr = malloc(newsize);
	if (newptr == NULL)
		return (NULL);
	if (newsize < oldsize)
		_memcpy(newptr, oldptr, newsize);
	else
		_memcpy(newptr, oldptr, oldsize);

	free(oldptr);

	return (newptr);
}

/**
 * grid_realloc - allocates new memory block for a grid for stored data
 * @oldptr: old grid memory block
 * @oldsize: size of old memory block
 * @newsize: size of new memory block
 *
 * Return: None
 */
char **grid_realloc(char **oldptr, unsigned int oldsize, unsigned int newsize)
{
	char **newptr;
	unsigned int i;

	if (oldptr == NULL)
		return (malloc(newsize * sizeof(char *)));
	if (newsize == oldsize)
		return (oldptr);

	newptr = malloc(newsize * sizeof(char *));
	if (newptr == NULL)
		return (NULL);

	for (i = 0; i < oldsize; i++)
		newptr[i] = oldptr[i];

	free(oldptr);

	return (newptr);
}

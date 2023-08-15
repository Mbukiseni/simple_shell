#include "shell.h"

/**
 * bfree - releases a pointer and sets its address to NULL
 * @ptr: address of the pointer to be freed
 *
 * Return: 1 if releases, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

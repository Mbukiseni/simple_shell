#include "shell.h"

/**
 * bfree - frees a pointer
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

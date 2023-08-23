#include "main.h"

/**
 * copyPtr - copy pointer to buffer and free buffer
 * @ptr: pointer
 * @ptr_len: pointer len (size)
 * @buf: buffer
 * @buf_len: buffer len (size)
 * Return: nothing
 */

void copyPtr(char **ptr, size_t *ptr_len, char *buf, size_t buf_len)
{
	if (*ptr_len < buf_len || *ptr == NULL)
	{
		if (buf_len > 32)
			*ptr_len = buf_len;
		else
			*ptr_len = 32;
		*ptr = buf;
	}
	else
	{
		_strcpy(*ptr, buf);
		free(buf);
	}
}

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @len: length of ptr
 * @new_len: new length of ptr
 * Return: nothing
 */

void *_realloc(char *ptr, unsigned int len, unsigned int new_len)
{
	unsigned int i = 0;
	char *buffer;
	char *char_ptr;

	if (ptr == NULL)
	{
		buffer = malloc(new_len);
		if (buffer == NULL)
			return (NULL);

		return (buffer);
	}

	if (len == new_len)
		return (ptr);

	if (ptr != NULL && len == 0)
	{
		free(ptr);
		return (NULL);
	}
	else
		char_ptr = ptr;

	buffer = malloc(len * sizeof(char_ptr));
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}

	while (i < new_len && i < len)
		buffer[i++] = *char_ptr++;

	free(ptr);
	return (buffer);
}


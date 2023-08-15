#include "shell.h"

/**
 * _eputs - produces an output of the provided string
 * @str: the string that will be displayed
 *
 * Return: 0
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - outputs the character 'c' to the standard error stream
 * @c: The specific character to be displayed
 *
 * Return: On success 1.
 * On error, the function returns -1 and sets errno accordingly.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - writes the character 'c' to the provided file descriptor (fd)
 * @c: The character to be written
 * @fd: The file descriptor to which the output will be written
 *
 * Return: On success 1.
 * On error, the function returns -1, and errno is adjusted accordingly.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - displays the provided string
 * @str: the string that will be displayed
 * @fd: the file descriptor to which the content will be written
 *
 * Return: the count of characters that have been placed.
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

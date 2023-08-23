#include "main.h"

/**
 * _getline - get line from file
 * @fstream: file stream
 * @f: file
 * @f_len: file length
 * Return: number of characters read
 */

ssize_t _getline(char **f, size_t *f_len, FILE *fstream)
{
	static ssize_t j;
	ssize_t getnumber;
	int count;
	char c = 'c', *buffer = malloc(*f_len + 1);

	if (buffer == NULL)
		return (-1);
	if (j == 0)
		fflush(fstream);
	else
		return (-1);

	buffer[*f_len] = '\0';
	j = 0;
	while (c != '\n')
	{
		count = read(STDIN_FILENO, &c, 1024);
		if (count == -1 || (count == 0 && j == 0))
		{
			free(buffer);
			return (-1);
		}
		if (j >= 32)
		{
			buffer = _realloc(buffer, j, j + 32);
		}
		if (c != '\n' && c != EOF)
		{
			buffer[j] = c;
			j++;
			continue;
		}
		buffer[j++] = '\n';
		buffer[j] =  '\0';
		copyPtr(f, f_len, buffer, j);
		getnumber = j;
	}
	if (count != 0)
		j = 0;
	return (getnumber);
}

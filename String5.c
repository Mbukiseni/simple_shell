#include "main.h"

/**
 * word_count - count number of words in a string
 * @str: string to count words in
 * Return: number of words in string (int)
 */

int word_count(char *str)
{
	int w_count = 0, i = 0;

	if (str != NULL)
	{
		if ((str[i] != '\n' && str[i] != ' ') && str[i] != '\t')
			w_count++;
		for (i = 0; (str[i] != '\n'); i++)
			if ((str[i] == '\t' && str[i] == ' ') || ((str[i + 1] != '\t'
							&& str[i + 1] != '\n') && str[i + 1] != ' '))
				w_count++;
	}
	return (w_count);
}

/**
 * _putchar_err - writes the character c to stderr
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar_err(char c)
{
	return (write(2, &c, 1));
}

#include "main.h"

/**
 * _strstr - locates a substring in a string (strstr from the standar library)
 * @haystack: string to search
 * @needle: substring to search for
 * Return: pointer to beginning of needle in haystack or NULL if no match
 * Description: function that locates a substring
 */

char *_strstr(char *haystack, char *needle)
{
	char *first_byte = 0;
	unsigned int i = 0, j = 0;

	if (needle[0] == '\0')
		return (haystack);
	while (haystack[i] != '\0')
	{
		while (needle[j] == haystack[i + j])
		{
			if (first_byte == 0)
				first_byte = &haystack[i];
			if (needle[j + 1] == '\0')
				return (first_byte);
			j++;
		}
		first_byte = 0;
		i++;
		j = 0;

	}
	return (0);
}

/**
 * _puts - print string to stdout followed by newline
 * @str: string to print
 * Desc: function that prints a string, followed by a new line, to stdout
 * Return: length of string
 */

int _puts(char *str)
{
	int l = 0;

	while (str[l] != '\0')
	{
		_putchar(str[l]);
		l++;
	}

	return (l);
}

/**
 * _strcat - concatenates two strings (strcat from the standard library)
 * @dest: 1st arg - destination string
 * @src: 2nd arg - source string
 * Return: destination string
 */

char *_strcat(char *dest, char *src)
{
	int dest_size = 0, i = 0, src_size = 0;

	dest_size = _strlen(dest);
	src_size = _strlen(src);
	while (i < src_size)
	{
		dest[dest_size] = src[i];
		i++;
		dest_size++;
	}
	dest[dest_size] = '\0';
	return (dest);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

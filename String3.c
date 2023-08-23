#include "main.h"

/**
 * _puts_err - print string to stderr
 * @str: string to print
 * Desc: function that prints a string, to stderr
 * Return: nothing
 */

int _puts_err(char *str)
{
	int l = 0;

	while (str[l] != '\0')
	{
		write(2, &str[l], 1);
		l++;
	}
	return (l);
}


/**
 * _strtok - splits a string into tokens
 * @str: string to split.
 * @delim: delimiter.
 *
 * Return: string splited.
 */
char *_strtok(char str[], const char *delim)
{
	unsigned int i, bool;
	static char *splitted_str, *end_str;
	char *str_start;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted_str = str; /*Store first address*/
		i = _strlen(str);
		end_str = &str[i]; /*Store last address*/
	}
	str_start = splitted_str;
	if (str_start == end_str) /*Reaching the end*/
		return (NULL);

	for (bool = 0; *splitted_str; splitted_str++)
	{
		/*Breaking loop finding the next token*/
		if (splitted_str != str_start)
			if (*(splitted_str - 1) == '\0' && *splitted_str)
				break;
		/*Replacing delimiter for null char*/
		for (i = 0; delim[i]; i++)
		{
			if (*splitted_str == delim[i])
			{
				*splitted_str = '\0';
				if (splitted_str == str_start)
					str_start++;
				break;
			}
		}
		if (*splitted_str && bool == 0) /*Str != Delim*/
			bool = 1;
	}
	if (bool == 0) /*Str == Delim*/
		return (NULL);
	return (str_start);
}

/**
 * rev_string - reverses a string
 * @s: string to reverse
 * Return: no return.
 */
void rev_string(char *s)
{
	char *str, temp;
	int count = 0, i, j = 0;


	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 * Return: pointer to duplicated string
 */

char *_strdup(char *str)
{
	int i = 0, length = 0;
	char *buf = 0;

	if (str == 0)
		return (0);
	length = _strlen(str);
	buf = (char *)malloc(sizeof(char) *	(length + 1));
	if (buf == 0)
		return (NULL);
	while (str[i] != '\0')
	{
		buf[i] = str[i];
		i++;
	}
	buf[i] = '\0';

	return (buf);
}

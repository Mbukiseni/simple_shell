#include "main.h"

/**
 * _strlen - returns the length of a string
 * @str: string
 * Return: length of string
 */

size_t _strlen(char *str)
{
	size_t len = 0;

	if (str != NULL)
		while (str[len] != '\0')
			len++;

	return (len);
}

/**
 * split_tok - split string into tokens
 * @str: string to split
 * @delim: delimiter
 * Return: pointer to array of tokens
 */

char **split_tok(char *str, const char *delim)
{
	size_t i = 0, wc = 0, off_set = 0, j = 0, k = 0;
	char **array = NULL;

	if (str == NULL)
		return (NULL);
	wc = word_count(str);
	array = malloc((wc + 2) * sizeof(*array));
	if (array == NULL)
	{
		free(array);
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; )
	{
		if (str[i + 1] != '\n' && i == off_set &&
				(str[i] == '\t' || str[i] == *delim))
		{
			i++, off_set++;
				continue;
		}
		if (str[i] == '\t' || str[i + 1] == '\0' || str[i] == *delim)
		{
			if (str[i + 1] == '\n' && off_set == i)
				break;
			array[j] = malloc((i - off_set + 2) * sizeof(char));
			if (array[j] == NULL)
				return (NULL);
			k = 0;
			while ((str[off_set] != '\t' || str[off_set] != *delim) && off_set != i)
				array[j][k++] = str[off_set++];
			array[j][k] = '\0';
			off_set++, j++;
			if (str[off_set] == '\n')
				break;
		}
		i++;
	}
	array[j] = NULL;
	return (array);
}


/**
 * _strcmp - compare two strings
 * @s1: 1st arg - destination string
 * @s2: 2nd arg - source string
 * Return: 0 if strings are identical, else 1 or -1
 */

int _strcmp(char *s1, char *s2)
{
	int s1_length = 0, s2_length = 0, i = 0, res = 0, len = 0;

	s1_length = _strlen(s1);
	s2_length = _strlen(s2);
	if (s1_length <= s2_length)
		len = s1_length;
	else
		len = s2_length;
	while (i <= len)
	{
		res = s1[i] - s2[i];
		if (res != 0)
			return (res);
		i++;
	}
	return (res);
}

/**
 * _strcpy - copies the string pointed to by src,
 * @dest: destination string arg
 * @src: source string arg
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	size_t i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

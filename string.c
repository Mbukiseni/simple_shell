#include "shell.h"

/**
 * _strlen - calculates the size of a string
 * @s: the string for which to determine the length
 *
 * Return: whole number representing the extent of the string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - conducts a lexical comparison between two strings.
 * @s1: the 1st strang
 * @s2: the 2nd strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - verifies if "needle" commences with "haystack"
 * @haystack: string to look for
 * @needle: the portion of string to locate
 *
 * Return: memory location of the next character in "haystack," or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - joins two strings
 * @dest: the target buffer
 * @src: the input buffer
 *
 * Return: pointer to the target buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

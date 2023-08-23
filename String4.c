#include "main.h"

/**
 *  _reallocdp - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @size: size of ptr
 * @new_len: new size of ptr
 * Return: pointer to the new memory block
 */

char **_reallocdp(char **ptr, unsigned int size, unsigned int new_len)
{
	unsigned int i;
	char **new_ptr;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_len));

	if (new_len == size)
		return (ptr);

	new_ptr = malloc(sizeof(char *) * new_len);
	if (new_ptr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		new_ptr[i] = ptr[i];
	free(ptr);
	return (new_ptr);
}

/**
 * cmp_chars - compare chars in a string with a delimiter
 * @str: string to compare.
 * @delim: delimiter.
 * Return: 1 if true, 0 if false.
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * print_number - print an integer
 * @n: integer to print out to stdout
 * Return: void
 */
void print_number(int n)
{
	unsigned int numb = n;

	if (n < 0)
	{
		_putchar('-');
		numb = -n;
	}
	if (numb / 10)
	print_number(numb / 10);
	_putchar_err(numb % 10 + '0');
}

/**
 * isInt - checks if a string is an int
 * @str: string to check
 * Return: 1 if true, 0 if false
 */
int isInt(char *str)
{
	int i = 0, str_len = _strlen(str);

	if (str == NULL)
		return (1);
	while (i < str_len)
	{
		if (str[i] < 58 && str[i] > 47)
			i++;
		else
			return (0);
	}

	return (1);
}

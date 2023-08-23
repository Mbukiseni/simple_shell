#include "main.h"

/**
 * freeParam - free param struct members
 * @param: data parameter
 * Return: nothing
 */
void freeParam(data_t *param)
{
	freeArray(param->args);
	freeArray(param->_environ);
}

/**
 * freeArray - free string array
 * @array: array to free
 * Return: nothing
 */

void freeArray(char **array)
{
	int j = 0;

	if (array != NULL)
	{
		while (array[j] != NULL)
		{
			free(array[j++]);
		}
		free(array);
	}

}

/**
 * shellLoop - main loop
 * @param: data parameter
 * Return: nothing
 */

void shellLoop(data_t *param)
{
	ssize_t buffer = 32, status = 0;
	char *line_string = NULL;

	do {
		if (interactive(param))
			_puts("$ ");
		status = getline(&line_string, (size_t *)&buffer, stdin);
		if (status == -1)
		{
			param->arg = line_string;
			handle_getlin_err(param);
		}
		if (word_count(line_string) == 0 || line_string == NULL)
		{
			free(line_string);
			line_string = NULL;
			continue;
		}
		else
		{
			param->arg = line_string;
			param->args = split_tok(line_string, " ");
			if (shellExit(param))
				break;
			executeShell(param);
		}
		free(line_string);
		freeArray(param->args);
		line_string = NULL;
		param->args = NULL;
	} while (status + 1);

}

/**
 * _atoi - convert string to int
 * @s: string to convert
 * Return: converted int
 */

int _atoi(char *s)
{
	int i = 0;
	int n = 0;
	unsigned int res = 0;
	int minimum = 1;

	while (s[i])
	{
		if (s[i] == 45)
			minimum *= -1;
		while (s[i] <= 57 && s[i] >= 48)
		{
			n = 1;
			res = (res * 10) + (s[i] - '0');
			i++;
		}
		if (n == 1)
			break;
		i++;
	}
	res *= minimum;
	return (res);
}

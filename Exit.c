#include "main.h"

/**
 * rmComment - remove comment from getline string
 * @str: string to remove comment from
 * Return: string without comment
 */
char *rmComment(char *str)
{
	int i, upto;

	upto = 0;
	for (i = 0; str[i]; i++)
	{
		if (str[i] == '#')
		{
			if (i == 0)
			{
				free(str);
				return (NULL);
			}

			if (str[i - 1] == '\t' || str[i - 1] == ';' || str[i - 1] == '')
				upto = i;
		}
	}

	if (upto != 0)
	{
		str = _realloc(str, i, upto + 1);
		str[upto] = '\0';
	}

	return (str);
}

/**
 * handle_getlin_err - handle getline error
 * @param: data parameter
 * Return: nothing
 */
void handle_getlin_err(data_t *param)
{
	if (interactive(param))
		_putchar_err('\n');
	free(param->arg);
	freeParam(param);
	exit(0);
}

/**
 * shellExit - exit shell
 * @param: data parameter
 * Return: 1
 */

int shellExit(data_t *param)
{
	int error;

	if (_strcmp(param->args[0], "exit") == 0)
	{
		/*check if int*/
		if (param->args[1] != NULL)
		{
			if (isInt(param->args[1]))
			{
				error = _atoi(param->args[1]);
				if (error < 0)
				{
					free(param->arg);
					freeParam(param);
					exit(2);
				}
				free(param->arg);
				freeParam(param);
				exit(error);
			}
			else
			{
				exit_code_err(param);
				return (0);
			}
		}
		else
		{
			free(param->arg);
			return (1);
		}
	}
	return (0);
}

/**
 * exit_code_err - print error message
 * @param: data param
 * Return: nothing
 */
void exit_code_err(data_t *param)
{
	param->errcount++;
	_puts_err(param->av[0]);
	_puts_err(": ");
	print_number(param->errcount);
	_puts_err(": ");
	_puts_err(param->args[0]);
	_puts_err(": Illegal number: ");
	_puts_err(param->args[1]);
	_puts_err("\n");
	if (!interactive(param))
	{
		free(param->arg);
		freeParam(param);
		exit(2);
	}
}


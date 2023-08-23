#include "main.h"

/**
 * unsetEnv - unset environmental variable
 * @param: data parameter
 * Return: 1
 */
int unsetEnv(data_t *param)
{

	int i;
	char *varen, *nameen;

	if (param->args[1] == NULL)
	{
		_puts_err(param->av[0]);
		_puts_err(": ");
		_puts_err(param->args[0]);
		_puts_err(": add variale usage: unsetenv VARIABLE\n");
		return (1);
	}


	for (i = 0; param->_environ[i]; i++)
	{
		varen = _strdup(param->_environ[i]);
		nameen = _strtok(varen, "=");
		if (_strcmp(nameen, param->args[1]) == 0)
		{
			free(param->_environ[i]);
			while (param->_environ[i] != NULL)
			{
				param->_environ[i] = param->_environ[i + 1];
				i++;
			}
			free(varen);
			return (1);
		}
		free(varen);
	}
	_puts_err(param->av[0]);
	_puts_err(": :env variable :");
	_puts_err(param->args[1]);
	_puts_err(": not found\n");
	return (1);
}

/**
 * setEnv - set environmental variable
 * @param: data parameter
 * Return: 1
 */

int setEnv(data_t *param)
{
	if (param->args[2] != NULL && param->args[1] != NULL)
	{
		set_env(param->args[1], param->args[2], param);
		return (1);
	}

	_puts_err(param->av[0]);
	_puts_err(": ");
	_puts_err(param->args[0]);
	_puts_err(": Ivalid variabe or value: usage: setenv VARIABLE VALUE\n");
	return (1);
}

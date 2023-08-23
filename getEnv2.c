#include "main.h"

/**
 * copy_info - copies info to create a new env or alias
 * @name: name of env or alias
 * @value: value of env or alias
 * Return: pointer to new env or alias.
 */
char *copy_info(char *name, char *value)
{
	char *newchar;
	int length_name, length_value, length;

	length_name = _strlen(name);
	length_value = _strlen(value);
	length = length_name + length_value + 2;
	newchar = malloc(sizeof(char) * (length));
	_strcpy(newchar, name);
	_strcat(newchar, "=");
	_strcat(newchar, value);
	_strcat(newchar, "\0");

	return (newchar);
}

/**
 * set_env - sets a new environment variable
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @param: data parameter
 * Return: nothing
 */
void set_env(char *name, char *value, data_t *param)
{
	int i;
	char *varia_envi, *name_envi;

	for (i = 0; param->_environ[i]; i++)
	{
		varia_envi = _strdup(param->_environ[i]);
		name_envi = _strtok(varia_envi, "=");
		if (_strcmp(name_envi, name) == 0)
		{
			free(param->_environ[i]);
			param->_environ[i] = copy_info(name_envi, value);
			free(varia_envi);
			return;
		}
		free(varia_envi);
	}

	param->_environ = _reallocdp(param->_environ, i, sizeof(char *) * (i + 2));
	param->_environ[i] = copy_info(name, value);
	param->_environ[i + 1] = NULL;
}
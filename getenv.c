#include "main.h"

/**
 * interactive - returns true if shell is interactive mode
 * @param: application data
 *Return: if interactive mode 1 else 0
 */
int interactive(data_t *param)
{
	return (isatty(STDIN_FILENO) && param->readfd <= 2);
}

/**
 * printEnv - print environment
 * @param: data parameter
 * Return: 1 if success
 */

int printEnv(data_t *param)
{
	size_t i = 0;

	if (param->_environ == NULL || param->args == NULL)
	{
		return (0);
	}

	while (param->_environ[i] != NULL)
	{
		_puts(param->_environ[i]);
		_putchar('\n');
		i++;
	}

	return (1);
}


/**
 * cmp_env_name - compare environment variable name with name passed
 * @env: environment variable
 * @name: name to compare
 * Return: 1 if success
 */
int cmp_env_name(const char *env, const char *name)
{
	int j;

	for (j = 0; env[j] != '='; j++)
	{
		if (env[j] != name[j])
		{
			return (0);
		}
	}

	return (j + 1);
}

/**
 * findEnv - find environment variable
 * @name: name of the environment variable
 * @_environ: environment variables
 * Return: pointer to the environment variable
 */
char *findEnv(const char *name, char **_environ)
{
	char *ptrtoenv;
	int i, movi;

	ptrtoenv = NULL;
	movi = 0;

	for (i = 0; _environ[i]; i++)
	{
		/* If name and env are equal */
		movi = cmp_env_name(_environ[i], name);
		if (movi)
		{
			ptrtoenv = _environ[i];
			break;
		}
	}

	return (ptrtoenv + movi);
}

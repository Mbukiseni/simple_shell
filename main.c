#include "main.h"


/**
 * setEnviron - set environ
 * @param: data parameter
 * @environ: environmental variables
 * Return: nothing
 */

int setEnviron(data_t *param, char **environ)
{
	unsigned int i = 0;

	param->args = NULL;
	param->_environ = NULL;
	param->av = NULL;
	param->arg = NULL;
	param->path = NULL;
	param->env_pathstr = NULL;
	param->lnflag = 0;
	param->lncount = 0;
	param->readfd = 0;
	param->errcount = 0;

	while (environ[i] != NULL)
		i++;

	param->_environ =  malloc(sizeof(char *) * (i + 1));
	if (param->_environ == NULL)
		return (0);

	for (i = 0; environ[i] != NULL; )
	{
		param->_environ[i] = _strdup(environ[i]);
		i++;
	}

	param->_environ[i] = NULL;
	return (1);
}

/**
 * getSignal - get signal
 * @signal: signal
 */

void getSignal(int __attribute__((unused)) signal)
{
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * main - main function
 * @ac: argument count
 * @av: argument vector
 * @environ: environmental variables
 * Return: 0 on success
 */

int main(int  __attribute__((unused)) ac, char **av, char **environ)
{
	data_t parameter;

	if (av == NULL || ac > 1)
		return (0);
	signal(SIGINT, getSignal);

	if (!setEnviron(&parameter, environ))
		return (0);
	param.av = av;

	shellLoop(&parameter);
	freeParam(&parameter);

	exit(0);
}

#include "main.h"

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

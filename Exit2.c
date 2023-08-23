#include "main.h"

/**
 * exit_frm_wait - exit from wait
 * @status: status
 * @param: data parameter
 * Return: nothing
 */

void exit_frm_wait(int status, data_t *param)
{
	if (WEXITSTATUS(status) == 2)
	{
		free(param->arg);
		freeParam(param);
		exit(2);
	}
}


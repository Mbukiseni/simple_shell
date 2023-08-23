#include "main.h"

/**
 * get_buildInFunc - get select build in function
 * @param: commands to run  (char)
 * Return: pointer to function pointer
 */

int (*get_buildInFunc(data_t *param))(data_t *)
{
	buildIn_f func_arr[] = {
	{"cd", runCdFunc},
	{"help", helpCommand},
	{"^D", hdlCtrlCommand},
	{"env", printEnv},
	{"setenv", setEnv},
	{"unsetenv", unsetEnv},
	{NULL, NULL},
	};
	int i = 0;

	while (i < 6)
	{
		if ((_strcmp(func_arr[i].arg, param->args[0]) == 0))
		{
			param->errcount++;
			return (func_arr[i].f);
		}
		i++;
	}
	return (0);
}

/**
 * cdCommand - change directory command - builtin
 * @param: environ and args data.  args[0] = "cd".  args[1] =  directory.
 * Return: 1 on success
 */
int cdCommand(data_t *param)
{
	if (param->args[0] == NULL)
	{
		_puts_err(param->av[0]);
		_puts_err(": expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(param->args[1]) != 0)
			_puts("$ ");
	}
	return (1);
}
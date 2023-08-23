#include "main.h"

/**
 * runCdFunc - run cd command
 * @param: environ and args data
 * Return: 1 if success
 */

int runCdFunc(data_t *param)
{
	char *directory;
	int check_home, check_home2, is_working_dir;

	directory = param->args[1];
	if (directory != NULL)
	{
		check_home = _strcmp("$HOME", directory);
		check_home2 = _strcmp("~", directory);
		is_working_dir = _strcmp("--", directory);
	}

	if ( !check_home || directory == NULL || !is_working_dir || !check_home2)
	{
		cd_to_home(param);
		return (1);
	}

	if (_strcmp("-", directory) == 0)
	{
		cd_previous(param);
		return (1);
	}

	if (_strcmp("..", directory) == 0 || _strcmp(".", directory) == 0)
	{
		cd_dot(param);
		return (1);
	}
	cd_to(param);
	return (1);
}


#include "main.h"


/**
 * cd_to_home - changes to howme directory
 * @param: environ and args parameters
 * Return: nothing
 */
void cd_to_home(data_t *param)
{
	char *ppwd, *howme;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	ppwd = _strdup(pwd);

	howme = findEnv("HOME", param->_environ);

	if (howme == NULL)
	{
		set_env("OLDPWD", ppwd, param);
		free(ppwd);
		return;
	}

	if (chdir(howme) == -1)
	{
		_puts_err("child directory failed");
		_puts_err(param->args[0]);

		free(ppwd);
		return;
	}

	set_env("OLDPWD", ppwd, param);
	set_env("PWD", howme, param);
	free(ppwd);
}

/**
 * cd_dot - go to parent directory
 * @param: environ and args data
 * Return: no return
 */
void cd_dot(data_t *param)
{
	char pwd[PATH_MAX];
	char *directory, *cppwd, *cp_strtok_pwd;

	getcwd(pwd, sizeof(pwd));
	cppwd = _strdup(pwd);
	set_env("OLDPWD", cppwd, param);
	directory = param->args[1];
	if (_strcmp(".", directory) == 0)
	{
		set_env("PWD", cppwd, param);
		free(cppwd);
		return;
	}
	if (_strcmp("/", cppwd) == 0)
	{
		free(cppwd);
		return;
	}
	cp_strtok_pwd = cppwd;
	rev_string(cp_strtok_pwd);
	cp_strtok_pwd = _strtok(cp_strtok_pwd, "/");
	if (cp_strtok_pwd != NULL)
	{
		cp_strtok_pwd = _strtok(NULL, "\0");

		if (cp_strtok_pwd != NULL)
			rev_string(cp_strtok_pwd);
	}
	if (cp_strtok_pwd != NULL)
	{
		chdir(cp_strtok_pwd);
		set_env("PWD", cp_strtok_pwd, param);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", param);
	}
	free(cppwd);
}


/**
 * cd_previous - changes to the previous directory
 * @param: args and environs
 * Return: no return
 */
void cd_previous(data_t *param)
{
	char pwd[PATH_MAX];
	char *ppwd, *p_oldpwd, *cppwd, *cp_oldpwd;

	getcwd(pwd, sizeof(pwd));
	cppwd = _strdup(pwd);

	p_oldpwd = findEnv("OLDPWD", param->_environ);

	if (p_oldpwd == NULL)
		cp_oldpwd = cppwd;
	else
		cp_oldpwd = _strdup(p_oldpwd);

	set_env("OLDPWD", cppwd, param);

	if (chdir(cp_oldpwd) == -1)
		set_env("PWD", cppwd, param);
	else
		set_env("PWD", cp_oldpwd, param);

	ppwd = findEnv("PWD", param->_environ);

	write(STDOUT_FILENO, ppwd, _strlen(ppwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cppwd);
	if (p_oldpwd)
		free(cp_oldpwd);

	chdir(ppwd);
}


/**
 * cd_to - changes to given directory
 * @param: environ and args param
 * Return: no return
 */
void cd_to(data_t *param)
{
	char pwd[PATH_MAX];
	char *directory, *cppwd, *cp_dir;

	getcwd(pwd, sizeof(pwd));

	directory = param->args[1];
	if (chdir(directory) == -1)
	{
		_puts_err("child directory failed");
		_puts_err(param->args[0]);
		return;
	}

	cppwd = _strdup(pwd);
	set_env("OLDPWD", cppwd, param);

	cp_dir = _strdup(directory);
	set_env("PWD", cp_dir, param);

	free(cppwd);
	free(cp_dir);

}
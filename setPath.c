#include "main.h"

/**
 * handle_path - handle path
 * @param: data structure
 * Return: 1 on success, -1 on failure
 */
int handle_path(data_t *param)
{
	char *path = NULL;

	param->path = param->args[0];
	if (param->lnflag == 1)
	{
		param->lncount++;
		param->lnflag = 0;
	}
	path = pathSearch(param);
	if (path)
	{
		param->path = path;
		return (1);
	}

	if (isvalidPath(param->args[0]) && (param->args[0][0] == '/' || interactive(param) ||
			findEnv("PATH=", param->_environ)))
		return (1);

	return (-1);
}


/**
 * pathSearch - search for path in env path string
 * @param: data structure
 * Return: path on success, NULL on failure
 */
char *pathSearch(data_t *param)
{
	char *path, *pathstr = NULL, *com = NULL;
	int i = 0, offset = 0;

	pathstr = findEnv("PATH=", param->_environ);
	param->env_pathstr = pathstr;
	com = param->args[0];
	if (!pathstr)
		return (NULL);
	if (_strstr(com, "./") && (_strlen(com) > 2))
	{
		if (isvalidPath(com))
			return (com);
	}
	while (1)
	{
		if (pathstr[i] == ':' || !pathstr[i])
		{
			path = getenvPath(pathstr, offset, i);
			if (!*path)
				_strcat(path, com);
			else
			{
				_strcat(path, "/");
				_strcat(path, com);
			}
			if (isvalidPath(path))
				return (path);
			if (!pathstr[i])
				break;
			offset = i;
		}
		i++;
	}
	return (NULL);
}

/**
 * getenvPath - get path from env
 * @envpath: path from env
 * @offset: starting index
 * @limit: ending index
 * Return: path
 */
char *getenvPath(char *envpath, int offset, int limit)
{
	static char strbuf[512];
	int frst = 0, i = 0;

	for (i = 0, frst = offset; frst < limit; frst++)
	{
		if (envpath[frst] != ':')
			strbuf[i++] = envpath[frst];
	}
	strbuf[i] = 0;
	return (strbuf);
}

/**
 * isvalidPath - check if path is valid
 * @path: path to check for validity
 * Return: 1 if valid, 0 if not
 */
int isvalidPath(char *path)
{
	struct stat str;

	if (!path || stat(path, &str))
		return (0);

	if (str.st_mode & S_IFREG)
		return (1);

	return (0);
}

#ifndef _MAIN_H_
#define _MAIN_H_

#define BUF_SIZE 64

#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <stdio.h>
#include <limits.h>
#include <stddef.h>
#include <sys/types.h>



/**
 * struct data - data structure
 * @av: argument vector
 * @er_status: error status
 * @arg: argument
 * @args: arguments
 * @_environ: environmental variables
 * @path: path
 * @env_pathstr: environmental path string
 * @lnflag: line flag
 * @lncount: line count
 * @errcount: error count
 * @readfd: read file descriptor
 */
typedef struct data
{
	char **av;
	int er_status;
	char *arg;
	char **args;
	char **_environ;
	char *path;
	char *env_pathstr;
	int lnflag;
	unsigned int lncount;
	int errcount;
	int readfd;
} data_t;


/**
 * struct builtInFunc - builtin functions
 * @arg: argument
 * @f: function
 */
typedef struct builtInFunc
{
	char *arg;
	int (*f)(data_t *);
} buildIn_f;

	
	/*builtinFunc.c */
	int helpCommand(data_t *param);
	int hdlCtrlCommand(data_t *param);

	/*builtinFunc2.c*/
	int (*get_buildInFunc(data_t *param))(data_t *param);
	int cdCommand(data_t *param);

	/*cdfunc.c*/
	void cd_dot(data_t *param);
	void cd_to(data_t *param);
	void cd_previous(data_t *param);
	void cd_to_home(data_t *param);

	/*cdfunc2.c*/
	int runCdFunc(data_t *param);

	/*getEnv.c*/
	int printEnv(data_t *param);
	char *findEnv(const char *name, char **_environ);
	int cmp_env_name(const char *env, const char *name);
	void set_env(char *name, char *value, data_t *param);

	/*geEnv2.c*/
	char *copy_info(char *name, char *value);
	int interactive(data_t *param);

	/*getLine.c*/
	ssize_t _getline(char **f, size_t *f_len, FILE *fstream);
	int handle_getline(data_t *param);
	
	/*lunchShell.c*/
	int executeShell(data_t *param);
	void Print_N_err(data_t *param);

	/*Exit.c*/
	char *rmComment(char *str);
	void handle_getlin_err(data_t *param);
	void exit_code_err(data_t *param);
	int shellExit(data_t *param);

	/*Exit2.c*/
	void exit_frm_wait(int status, data_t *param);


	/*String.c*/
	size_t _strlen(char *str);
	int _strcmp(char *s1, char *s2);
	char *_strcpy(char *dest, char *src);
	char **split_tok(char *str, const char *delim);

	/*String2.c*/
	int _putchar(char c);
	int _puts(char *str);
	char *_strcat(char *dest, char *src);
	char *_strstr(char *haystack, char *needle);

	/*String3.c*/
	int _puts_err(char *str);
	char *_strdup(char *str);
	void rev_string(char *s);
	char *_strtok(char str[], const char *delim);

	/*String4.c*/
	char **_reallocdp(char **ptr, unsigned int size, unsigned int new_len);
	int cmp_chars(char str[], const char *delim);
	int isInt(char *str);
	void print_number(int num);

	/*String5.c*/
	int _putchar_err(char c);
	int word_count(char *str);

	/*shell_loop.c*/
	void freeParam(data_t *param);
	int _atoi(char *s);
	void freeArray(char **array);
	void shellLoop(data_t *param);

	/*stdlib.c*/
	void *_realloc(char *ptr, unsigned int len, unsigned int new_len);
	void copyPtr(char **ptr, size_t *ptr_len, char *buf, size_t buf_len);



	/*setPath.c*/
	char *pathSearch(data_t *param);
	char *getenvPath(char *envpath, int offset, int limit);
	int isvalidPath(char *path);
	int handle_path(data_t *param);


	/*setEnv.c*/
	int setEnv(data_t *param);
	int unsetEnv(data_t *param);

	/*main.c*/
	void getSignal(int signal);
	int setEnviron(data_t *param, char **environ);

#endif /*main.h*/

#include "header_shell.h"

/**
 * execute_func - executes functions
 * @exec: executable with path
 * @input_user: array of arguments
 */
void execute_func(char *exec, char **input_user, ssize_t flag, char **env)
{
	int status;
	ssize_t family_member;

	family_member = fork();
	if (family_member == 0)
		execve(exec, input_user, env);
	else
		wait(&status);

	if (flag == 1)
		free(exec);
}

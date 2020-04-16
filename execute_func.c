#include "header_shell.h"

/**
 * execute_func - executes functions
 * @exec: executable with path
 * @input_user: array of arguments
 * @flag: flag to free exec if 1
 * Return: Exit status
 */
int execute_func(char *exec, char **input_user, ssize_t flag)
{
	int status;
	ssize_t family_member;
	int s = 0;

	family_member = fork();
	if (family_member == 0)
		execve(exec, input_user, environ);

	wait(&status);
	s = WEXITSTATUS(status);

	if (flag == 1)
		free(exec);

	return (s);
}

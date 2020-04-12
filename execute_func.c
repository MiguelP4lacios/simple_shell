#include "header_shell.h"

/**
 * execute_func - executes functions
 * @exec: executable with path
 * @input_user: array of arguments
 */
void execute_func(char *exec, char **input_user)
{
	int status;
	ssize_t family_member;

	family_member = fork();
	if (family_member == 0)
		execve(exec, input_user, NULL);
	else
		wait(&status);
	free(exec);
}

#include "header_shell.h"
/**
 * print_env - built-in print env
 * return : nothing
*/
void print_env(void)
{
	size_t i = 0;

	while (environ[i])
	{
		write(STDIN_FILENO,environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO,"\n",1);
		i++;
	}
}

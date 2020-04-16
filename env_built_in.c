#include "header_shell.h"
/**
 * print_env - built-in print env
 * return : nothing
*/
ssize_t print_env(void)
{
	size_t i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}

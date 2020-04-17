#include "header_shell.h"
/**
 * print_env - built-in print env
 * Return: nothing
*/
ssize_t print_env(void)
{
	size_t i = 0;
	char newLine = '\n';

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, &newLine, 1);
		i++;
	}
	return (0);
}

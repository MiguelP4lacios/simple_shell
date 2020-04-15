#include "header_shell.h"
/**
 * print_env - built-in print env
 * @env: envoirment
 * return : nothing
*/
void print_env(void)
{
	size_t i = 0;

	while (environ[i])
	{
		write(1,environ[i], _strlen(environ[i]));
		write(1,"\n",1);
		i++;
	}
}

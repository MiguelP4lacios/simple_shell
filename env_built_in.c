#include "header_shell.h"
/**
 * print_env - built-in print env
 * @env: envoirment
 * return : nothing
*/
void print_env(char **env)
{
	size_t i = 0;

	while (env[i])
	{
		write(1, env[i], _strlen(env[i]));
		i++;
	}
}

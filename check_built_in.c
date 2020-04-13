#include "header_shell.h"
/**
 * check_built_in - check the built-in
 * @input: input user
 * @buff: buffer input
 * @head_path: PATH
 * return : nothing
 *
*/
void check_built_in(char **input, char *buff, list_path *head_path, char **env)
{
	if (_strcmp(input[0], "exit") == 0)
	{
		exit_built_in(input, buff, head_path);
	}
	if (_strcmp(input[0], "env") == 0)
	{
		print_env(env);
	}
}

#include "header_shell.h"
/**
 * help_built_in - info of the built in
 * @input: argument
 * Return: sussues 0 or 3 fail
*/
ssize_t help_built_in(char **input)
{
	if (input[1] != NULL)
	{
		if (_strcmp(input[1], "env") == 0)
		{
			help_env();
			return (0);
		}
		else if (_strcmp(input[1], "exit") == 0)
		{
			help_exit();
			return (0);
		}
		else if (_strcmp(input[1], "help") == 0)
		{
			help_help();
			return (0);
		}
		else if (_strcmp(input[1], "setenv") == 0)
		{
			help_setenv();
			return (0);
		}
		else if (_strcmp(input[1], "unsetenv") == 0)
		{
			help_unsetenv();
			return (0);
		}
		else if (_strcmp(input[1], "cd") == 0)
		{
			help_cd();
			return (0);
		}
		else
			return (3);
	}
	else
	{
		help();
		return (0);
	}
}

#include "header_shell.h"
/**
 * 
 * 
 * 
*/
void help_built_in(char **input)
{
	if (_strcmp(input[1], "env") == 0)
	{
		help_env();
	}
	else if (_strcmp(input[1], "exit") == 0)
	{
		help_exit();
	}
	else if (_strcmp(input[1], "help") == 0)
	{
		help_help();
	}
	else
		return;
}
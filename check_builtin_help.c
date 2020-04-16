#include "header_shell.h"
/**
 * 
 * 
 * 
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
			return(0);
		}
		else if (_strcmp(input[1], "help") == 0 )
		{
			help_help();
			return(0);
		}
		else
			return (3);
	}
	else
	{
		return (3); /* all */
	}
}

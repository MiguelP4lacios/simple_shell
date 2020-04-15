#include "header_shell.h"
/**
 * exit_built_in - exit of the shell
 * @in: input
 * @b: buffer input
 * @h_p: head path
 * return: nothing
*/
void exit_built_in(char **in, char *b, list_path *h_p)
{
	size_t i = 0, status_exit, FV;

	if (in[1] != NULL)
	{
		while (in[1][i] != '\0')
		{
			if (_isdigit(in[1][i]) == 1)
			{
				FV = 1;
			}
			else
			{
				return;
			}
			i++;
		}
		if (FV == 1)
		{
			status_exit = _atoi(in[1]);
		}
	}
	else
	{
		status_exit = 0;
	}
	if (b)
		free(b);
	if (in)
	{
		for (i = 0; in[i]; i++)
			free(in[i]);
		free(in);
	}
	free_list_path(h_p);
	exit(status_exit);
}

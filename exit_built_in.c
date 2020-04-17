#include "header_shell.h"
/**
 * exit_built_in - exit of the shell
 * @in: input
 * @b: buffer input
 * @h_p: head path
 * @status: status exit
 * Return: success status or 5 fail
*/
ssize_t exit_built_in(char **in, char *b, list_path *h_p, ssize_t *status)
{
	size_t i = 0, FV;

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
				*status = 2;
				return (5);
			}
			i++;
		}
		if (FV == 1)
		{
			*status = _atoi(in[1]);
		}
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
	exit(*status);
}

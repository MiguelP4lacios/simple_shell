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
	size_t i;

	if (b)
		free(b);
	if (in)
	{
		for (i = 0; in[i]; i++)
			free(in[i]);
		free(in);
	}
	free_list_path(h_p);
	exit(0);
}

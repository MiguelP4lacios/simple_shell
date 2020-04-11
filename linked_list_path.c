#include "header_shell.h"

/**
 * linked_path - creates a linked list of the path
 * @env: enviornment
 * Return: pointer to linked list
 */
list_path *linked_path(char **env)
{
	char select = ':';
	char *path = NULL;
	int num_paths, len_dir, i, j;
	char *p = NULL;
	list_path *head = NULL;

	path = _getenv("PATH", env);
	num_paths = countwords(path, select);

	for (i = 0; i < num_paths; i++)
	{
		len_dir = strlen_select(path, select);

		p = malloc(sizeof(char) * (len_dir + 1 + 1));
		for (j = 0; j < len_dir; j++)
		{
			p[j] = path[j];
		}
		p[j] = '/';
		p[j + 1] = '\0';
		add_node_end(&head, p);
		path = path + len_dir + 1;
	}

	return (head);
}

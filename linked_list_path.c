#include "header_shell.h"

/**
 * linked_path - creates a linked list of the path
 * Return: pointer to linked list
 */
list_path *linked_path(void)
{
	char select = ':';
	char *path = NULL;
	int num_paths, len_dir, i, j;
	char *p = NULL;
	list_path *head = NULL;

	path = _getenv("PATH", environ);
	num_paths = countwords(path, select);

	if (path[0] == ':')
	{
		p = malloc(sizeof(char) * (1 + 1 + 1));
		p[0] = '.';
		p[1] = '/';
		p[2] = '\0';
		add_node_end(&head, p);
		path++;
	}

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

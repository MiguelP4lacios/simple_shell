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

	path = _getenv("PATH");
	if (path == NULL)
		path = "";
	num_paths = countwords(path, select);
	for (i = 0; i < num_paths || path[0] == ':'; i++)
	{
		if (path[0] == ':')
		{
			p = malloc(sizeof(char) * (1 + 1 + 1));
			p[0] = '.';
			p[1] = '/';
			p[2] = '\0';
			add_node_end(&head, p);
			path = path + 1;
			num_paths++;
		}
		else
		{
			len_dir = strlen_select(path, select);

			p = malloc(sizeof(char) * (len_dir + 1 + 1));
			for (j = 0; j < len_dir; j++)
				p[j] = path[j];
			p[j] = '/';
			p[j + 1] = '\0';
			add_node_end(&head, p);
			path = path + len_dir;
			if (path[0] == ':' && i + 1 < num_paths)
				path = path + 1;
		}
	}

	return (head);
}

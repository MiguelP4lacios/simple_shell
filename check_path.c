#include "header_shell.h"

/**
 * check_path - check if path + input is exec
 * @exec: path + input
 * @head: head of list of path
 * @input_user: input user - first word
 * @numwords: number of words input
 * Return: 1 if path + input executable, 0 if not
 */
int check_path(char **exec, list_path *head, char *input_user, size_t numwords)
{
	size_t i;
	struct stat sb;

	for (i = 0; head != NULL; i++)
	{
		*exec = str_concat(head->dir_path, input_user);
		if (numwords > 0 && stat(*exec, &sb) == 0 && sb.st_mode & S_IXUSR)
			return (1);

		head = head->next;
		free(*exec);
	}

	return (0);
}

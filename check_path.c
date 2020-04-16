#include "header_shell.h"

/**
 * check_path - check if path + input is exec
 * @exec: path + input
 * @head: head of list of path
 * @input_user: input user - first word
 * @numwords: number of words input
 * Return: 0 not found
 * 1 (path + input) is executable --> free in execute_func
 * 2 (input) is executable
 * 3 (path + input) || (input) exist but not executable
 * 4 Do NOTHING
 */
int check_path(char **exec, list_path *head, char *input_user, size_t numwords, ssize_t *status)
{
	size_t i;
	struct stat sb;

	if (numwords == 0)
		return (0);

	if (_strcmp(input_user, ".") == 0)
	{
		*status = 127;
		return (4);
	}
	else if (_strcmp(input_user, "..") == 0)
	{
		*status = 127;
		return (3);
	}
	for (i = 0; head != NULL; i++)
	{
		*exec = str_concat(head->dir_path, input_user);
		if (stat(*exec, &sb) == 0 && sb.st_mode & S_IXUSR && !S_ISDIR(sb.st_mode))
			return (1);
		else if (stat(*exec, &sb) == 0)
		{
			*status = 126;
			free(*exec);
			return (3);
		}
		head = head->next;
		free(*exec);
	}
	*exec = input_user;
	if (stat(input_user, &sb) == 0 && sb.st_mode & S_IXUSR && !S_ISDIR(sb.st_mode))
		return (2);
	else if (stat(*exec, &sb) == 0)
	{
		*status = 126;
		return (3);
	}
	*status = 127;
	return (0);
}

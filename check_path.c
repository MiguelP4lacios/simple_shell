#include "header_shell.h"

/**
 * check_path - check if path + input is exec
 * @exec: path + input
 * @head: head of list of path
 * @in: input user - first word
 * @numwords: number of words input
 * @status: status of last command
 * Return: 0 not found
 * 1 (path + input) is executable --> free in execute_func
 * 2 (input) is executable
 * 3 (path + input) || (input) exist but not executable
 * 4 Do NOTHING
 */
int check_path(char **exec, list_path *head,
	       char *in, size_t numwords, ssize_t *status)
{
	size_t i;
	struct stat sb;

	if (numwords == 0)
		return (0);
	if (_strcmp(in, ".") == 0)
	{
		*status = 127;
		return (4);
	}
	else if (_strcmp(in, "..") == 0)
	{
		*status = 127;
		return (3);
	}
	for (i = 0; head != NULL && in[0] != '/'; i++)
	{
		*exec = str_concat(head->dir_path, in);
		if (stat(*exec, &sb) == 0 && sb.st_mode & S_IXUSR)
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
	*exec = in;
	if (stat(in, &sb) == 0 && sb.st_mode & S_IXUSR &&
	    (in[0] == '/' || in[0] == '.'))
		return (2);
	else if (stat(*exec, &sb) == 0 && (in[0] == '/' || in[0] == '.'))
	{
		*status = 126;
		return (3);
	}
	*status = 127;
	return (20);
}

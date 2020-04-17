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
	
}

#include "header_shell.h"

/**
 * free_list_path - frees a list
 * @head: pointer to head of list
 */
void free_list_path(list_path *head)
{
	list_path *aux_head = NULL;

	for (; head != NULL;)
	{
		aux_head = head;
		head = head->next;
		free(aux_head->dir_path);
		free(aux_head);
	}
}

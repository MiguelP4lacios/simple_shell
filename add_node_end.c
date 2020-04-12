#include "header_shell.h"

/**
 * add_node_end - adds a new node at the end of a list_path list
 * @head: pointer to the head of list
 * @dir: Pointer to string to add
 * Return: Address of the new element, or NULL if it failed
 */
list_path *add_node_end(list_path **head, char *dir)
{
	list_path *p_new_element = NULL;
	list_path *aux_head = NULL;
	size_t i;

	p_new_element = malloc(sizeof(list_path));
	if (p_new_element == NULL)
		return (NULL);

	p_new_element->dir_path = dir;
	p_new_element->next = NULL;

	aux_head = *head;

	if (aux_head == NULL)
		*head = p_new_element;
	else
	{
		for (i = 0; aux_head->next != NULL; i++)
			aux_head = aux_head->next;

		aux_head->next = p_new_element;
	}
	return (p_new_element);
}

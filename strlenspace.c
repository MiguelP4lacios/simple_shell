#include "header_shell.h"

/**
 * strlenspace - Counts characters until null or space is found
 * @s: Pointer to string to be count
 * Return: Number of characters count
 */
int strlenspace(char *s)
{
	int i;

	for (i = 0; s[i] != '\0' && s[i] != ' ' && s[i] != '\n'; i++)
	{
	}
	return (i);
}

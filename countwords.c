#include "header_shell.h"

/**
 * countwords - Counts words until a select char is found
 * @input: Pointer to string to be count
 * @select: the select char
 * Return: Number of words count
 */
size_t countwords(char *input, char select)
{
	ssize_t i;
	size_t numwords = 0;

	if (input[0] == '\n')
		return (0);
	else if (input[0] != select)
		numwords++;

	for (i = 1; input[i] != '\0'; i++)
	{
		if (input[i] == '\n' && input[i + 1] == '\0')
			break;

		if (input[i - 1] == select && input[i] != select)
			numwords++;
	}

	return (numwords);
}

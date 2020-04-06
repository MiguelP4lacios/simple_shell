#include "header_shell.h"

/**
 * countwords - Counts words until null is found
 * @input: Pointer to string to be count
 * Return: Number of words count
 */
size_t countwords(char *input)
{
	ssize_t i;
	size_t numwords = 0;

	if (input[0] == '\n')
		return (0);
	else if (input[0] != ' ')
		numwords++;

	for (i = 1; input[i] != '\0'; i++)
	{
		if (input[i] == '\n' && input[i + 1] == '\0')
			break;

		if (input[i - 1] == ' ' && input[i] != ' ')
			numwords++;
	}

	return (numwords);
}

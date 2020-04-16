#include "header_shell.h"

/**
 * countwords - Counts words until a s char is found
 * @in: Pointer to string to be count
 * @s: the selected char
 * Return: Number of words count
 */
size_t countwords(char *in, char s)
{
	ssize_t i;
	size_t numwords = 0;
	char s2 = s;

	if (s == ' ')
		s2 = 9;

	if (in[0] == '\n')
		return (0);
	else if (in[0] != s && in[0] != 9)
		numwords++;

	for (i = 1; in[i] != '\0'; i++)
	{
		if (in[i] == '\n' && in[i + 1] == '\0')
			break;

		if ((in[i - 1] == s && in[i] != s) || (in[i - 1] == s2 && in[i] != s2))
			numwords++;
	}

	return (numwords);
}

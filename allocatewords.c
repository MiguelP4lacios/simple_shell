#include "header_shell.h"

char **allocatewords(char *input, size_t numwords)
{
	char **master = NULL;
	char *p = NULL;
	size_t len = 0, i, j;

	master = malloc(sizeof(char *) * (numwords + 1));
	if (master == NULL)
		return (NULL);

	p = &input[0];
	for (i = 0; i < numwords; i++)
	{
		while (p[0] == ' ' || p[0] == '\n')
			p++;

		len = strlenspace(p);

		master[i] = malloc(sizeof(char) * (len + 1));
		if (master[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(master[j]);
			free(master);
		}

		for (j = 0; j < len; j++)
			master[i][j] = p[j];
		master[i][j] = '\0';

		p = p + j;
	}
	master[numwords] = NULL;

	return (master);
}

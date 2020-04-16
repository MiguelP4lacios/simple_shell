#include "header_shell.h"
char *realloc_str(char **master, size_t i, size_t j, char *var, size_t len_var);

/**
 * allocatewords - create array of words
 * @input: String with words for array
 * @numwords: Number of words in input
 * Return: pointer to array of words
 */
char **allocatewords(char *input, size_t *numwords, size_t status)
{
	char **master = NULL;
	char *p = NULL;
	size_t len = 0, i, j;

	master = malloc(sizeof(char *) * (*numwords + 1));
	if (master == NULL)
		return (NULL);

	p = &input[0];
	for (i = 0; i < *numwords; i++)
	{
		while (p[0] == ' ' || p[0] == 9)
			p++;

		len = strlen_select(p, ' ');

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
	master[*numwords] = NULL;

	master = check_words(master, numwords, status);

	return (master);
}

/**
 * check_words - check if the words have special caracters
 * @master: array of strings to check
 * @numwords: number of words
 * @status: status of last command
 * Return: array of change words if special character occurs
 */
char **check_words(char **master, size_t *numwords, size_t status)
{
	size_t i, j, k, l, terminal, len_string;
	char *var = NULL;
	char *p = NULL;
	int len_var;

	for (i = 0; i < *numwords; i++)
	{
		if (master[i][0] == '#')
		{
			for (k = i; k < *numwords; k++)
			{
				free(master[k]);
				master[k] = NULL;
			}
			*numwords = i;
			return (master);
		}

		for (j = 0; master[i][j] != '\0'; j++)
		{
			if (master[i][j] == '$')
			{
				if (master[i][j + 1] == '$')
				{
					terminal = getpid();
					master[i] = realloc_special_num(terminal, master, i, j);
				}
				else if (master[i][j + 1] == '?')
				{
					master[i] = realloc_special_num(status, master, i, j);
				}
				else if (_isalpha(master[i][j + 1]) == 1 || master[i][j + 1] == '_')
				{
					for (len_var = 0; _isalpha(master[i][j + len_var + 1]) == 1 || master[i][j + len_var + 1] == '_' || _isdigit(master[i][j + len_var + 1]); len_var++)
					{
					}

					p = malloc(sizeof(char) * (len_var + 1));
					for (k = j + 1; k < len_var + j + 1; k++)
					{
						p[k - j - 1] = master[i][k];
					}
					p[len_var] = '\0';
					var = _getenv(p, environ);
					free(p);
					p = NULL;

					printf("len_var + 1 = %d\n", len_var + 1);
					printf("len_master = %d\n", _strlen(master[i]));
					if (var != NULL || len_var + 1 != _strlen(master[i]))
					{
						master[i] = realloc_str(master, i, j, var, len_var);
					}
					else
					{
						for (k = i; master[k + 1] != NULL; k++)
						{
							len_string = _strlen(master[k + 1]);
							p = malloc(sizeof(char) * len_string + 1);
							for (l = 0; l < len_string; l++)
							{
								p[l] = master[k + 1][l];
							}
							p[l] = '\0';
							free(master[k]);
							master[k] = p;
						}
						free(master[k]);
						master[k] = NULL;
						*numwords = k;
					}
				}
			}
		}
	}

	return (master);
}

/**
 * realloc_str - insert number in master[i], position j
 * @number: Number to be inserted
 * @master: array of strings, with the word to be modify
 * @i: position of word in master
 * @j: position of letter in word of master
 * Return: pointer to modified word
 */
char *realloc_str(char **master, size_t i, size_t j, char *var, size_t len_var)
{
	size_t k, len, len_word, len_value;
	char *p = NULL;

	if (var == NULL)
		len_value = 0;
	else
		len_value = _strlen(var);

	len_word = _strlen(master[i]);

	len = len_value + len_word - len_var - 1 + 1;

	p = malloc(sizeof(char) * (len));

	for (k = 0; k < len - 1; k++)
	{
		if (k < j)
			p[k] = master[i][k];
		else if (k >= j && k < j + len_value)
		{
			p[k] = var[k - j];
		}
		else
		{
			p[k] = master[i][k - len_value + len_var + 1];
		}
	}
	p[len - 1] = '\0';
	free(master[i]);
	return (p);
}

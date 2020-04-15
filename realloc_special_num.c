#include "header_shell.h"

/**
 * realloc_special_num - insert number in master[i], position j
 * @number: Number to be inserted
 * @master: array of strings, with the word to be modify
 * @i: position of word in master
 * @j: position of letter in word of master
 * Return: pointer to modified word
 */
char *realloc_special_num(size_t number, char **master, size_t i, size_t j)
{
	size_t aux = number, len_number, len_word, len, k;
	char *p = NULL;

	for (len_number = 1; aux / 10 != 0; len_number++)
		aux = aux / 10;
	len_word = _strlen(master[i]);
	len = len_word - 2 + len_number + 1;

	p = malloc(sizeof(char) * (len));
	for (k = 0; k < len; k++)
	{
		if (k < j)
			p[k] = master[i][k];
		else if (k == j)
			k = print_number(number, p, k);
		else
		{
			p[k - 1] = master[i][k - len_number + 1];
		}
	}
	p[len - 1] = '\0';
	free(master[i]);
	return (p);
}

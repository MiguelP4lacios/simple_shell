#include "header_shell.h"

/**
 * not_found - Saves in buffer message to be print of no found
 * @j: Line of shell
 * @av: Argument zero of argv
 * @input_user: firt word of the user
 * @shell_count: buffer where the text will be save
 * Return: Len of text
 */
size_t not_found(size_t j, char *av, char *input_user, char **shell_count)
{
	size_t aux, len_arg, len_numline, len_first_input, i, k, sum;
	char nfound[] = ": not found\n";

	aux = j;
	len_arg = strlen(av);
	for (len_numline = 1; (aux + 1) / 10 != 0; len_numline++)
		aux = aux / 10;

	len_first_input = strlen(input_user);

	sum = len_arg + 2 + len_numline + 2 + len_first_input + 12;
	*shell_count = malloc(sizeof(char) * sum);

	for (i = 0; i < len_arg; i++)
		shell_count[0][i] = av[i];
	shell_count[0][i++] = ':';
	shell_count[0][i++] = ' ';

	i = print_number(j + 1, shell_count[0], i);
	shell_count[0][i++] = ':';
	shell_count[0][i++] = ' ';

	for (k = 0; input_user[k] != '\0'; k++, i++)
		shell_count[0][i] = input_user[k];

	for (k = 0; nfound[k] != '\0'; k++, i++)
		shell_count[0][i] = nfound[k];

	return (i);
}

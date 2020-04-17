#include "header_shell.h"

size_t error_m_illegal(size_t j, char *av, char **input, char **shell_count);

/**
 * error_m - Saves in buffer message to be print error message
 * @j: Line of shell
 * @av: Argument zero of argv
 * @input: input of the user
 * @shell_count: buffer where the text will be save
 * @flag: if flag is 3 denied if else not found
 * Return: Len of text
 */
size_t error_m(size_t j, char *av, char **input, char **shell_count, int flag)
{
	size_t aux, len_arg, len_numline;
	size_t len_first_input, len_mes, i, k, sum;
	char nfound[] = ": not found\n";
	char denied[] = ": Permission denied\n";

	if (flag == 5)
	{
		i = error_m_illegal(j, av, input, shell_count);
		return (i);
	}
	aux = j;
	len_arg = _strlen(av);
	for (len_numline = 1; (aux + 1) / 10 != 0; len_numline++)
		aux = aux / 10;
	len_first_input = _strlen(input[0]);
	if (flag == 3)
		len_mes = 20;
	else
		len_mes = 12;

	sum = len_arg + 2 + len_numline + 2 + len_first_input + len_mes;
	*shell_count = malloc(sizeof(char) * sum);

	for (i = 0; i < len_arg; i++)
		shell_count[0][i] = av[i];
	shell_count[0][i++] = ':';
	shell_count[0][i++] = ' ';

	i = print_number(j + 1, shell_count[0], i);
	shell_count[0][i++] = ':';
	shell_count[0][i++] = ' ';

	for (k = 0; input[0][k] != '\0'; k++, i++)
		shell_count[0][i] = input[0][k];

	if (flag == 3)
		for (k = 0; denied[k] != '\0'; k++, i++)
			shell_count[0][i] = denied[k];
	else
		for (k = 0; nfound[k] != '\0'; k++, i++)
			shell_count[0][i] = nfound[k];
	return (i);
}

/**
 * error_m_illegal - Saves in buffer message to be print error message
 * @j: Line of shell
 * @av: Argument zero of argv
 * @input: input of the user
 * @shell_count: buffer where the text will be save
 * Return: Len of text
 */
size_t error_m_illegal(size_t j, char *av, char **input, char **shell_count)
{
	size_t aux, len_arg, len_numline;
	size_t len1, len_mes = 18, i, k, sum, len2;
	char Illegal[] = ": Illegal number: ";

	aux = j;
	len_arg = _strlen(av);
	for (len_numline = 1; (aux + 1) / 10 != 0; len_numline++)
		aux = aux / 10;
	len1 = _strlen(input[0]);
	len2 = _strlen(input[1]);

	sum = len_arg + 2 + len_numline + 2 + len2 + len_mes + len1 + 2;
	*shell_count = malloc(sizeof(char) * sum);

	for (i = 0; i < len_arg; i++)
		shell_count[0][i] = av[i];
	shell_count[0][i++] = ':';
	shell_count[0][i++] = ' ';

	i = print_number(j + 1, shell_count[0], i);
	shell_count[0][i++] = ':';
	shell_count[0][i++] = ' ';

	for (k = 0; input[0][k] != '\0'; k++, i++)
		shell_count[0][i] = input[0][k];
	for (k = 0; Illegal[k] != '\0'; k++, i++)
		shell_count[0][i] = Illegal[k];

	for (k = 0; input[1][k] != '\0'; k++, i++)
		shell_count[0][i] = input[1][k];

	shell_count[0][i++] = '\n';
	return (i);
}

#include "header_shell.h"
/**
 * setenv_built_in - Initialize a new environment variable,
 * or modify an existing one
 * @input: Array of strings, input user
 * @status: status exit
 * Return: 0 always
 */
ssize_t setenv_built_in(char **input, ssize_t *status)
{
	char *p_value = NULL;
	char *p = NULL;
	ssize_t len_var, len_env;

	if (input[1] == NULL)
	{
		write(STDERR_FILENO, "usage: setenv VARIABLE VALUE", 28);
		*status = 2;
		return (0);
	}

	len_var = _strlen(input[1]);
	p_value = _getenv(input[1]);

	for (len_env = 0; environ[len_env] != NULL; len_env++)
	{
	}
	p = malloc(sizeof(char) * (len_var + 1 + 1));
	free(p);
	p = NULL;

	if (p_value == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		p_value[0] = 'H';
		printf("%s\n", p_value);
	}
	return (0);
}

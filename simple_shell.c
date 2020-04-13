#include "header_shell.h"

/**
 * main - simple_shell main
 * @ac: number of arguments
 * @av: Array of arguments
 * @env: enviornment
 * Return: 0 if success
 */
int main(int ac __attribute__((unused)), char *av[], char **env)
{
	ssize_t nread = 0, flag = 0, status = 0;
	size_t size = 0, numwords = 0, i, j;
	char *exec = NULL, *buffer = NULL, *shell_count = NULL;
	char **input_user = NULL;
	list_path *head_path = NULL;
	char **auxenv;

	signal(SIGINT, signal_handler);

	head_path = linked_path(env);
	for (j = 0;; j++)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 2);

		nread = _getline(&buffer, &size, stdin);
		if (nread == -1)
			break;

		numwords = countwords(buffer, ' ');
		input_user = allocatewords(buffer, numwords);
		if (input_user[0] != NULL)
			check_built_in(input_user, buffer, head_path, env);
		flag = check_path(&exec, head_path, input_user[0], numwords);

		if (flag != 0)
			status = execute_func(exec, input_user, flag, env);
		else if (numwords > 0)
		{
			i = not_found(j, av[0], input_user[0], &shell_count);
			write(STDOUT_FILENO, shell_count, i);
			free(shell_count);
		}
		for (i = 0; i < numwords; i++)
			free(input_user[i]);
		free(input_user);
	}
	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "\n", 1);

	free_list_path(head_path);
	free(buffer);
	return (status);
}

void signal_handler(int signal __attribute__((unused)))
{
	write(STDOUT_FILENO, "\n$ ", 3);
}

#include "header_shell.h"

/**
 * main - simple_shell main
 * Return: 0 if success
 */
int main(void)
{
	ssize_t nread = 0, family_member;
	size_t size = 0, numwords = 0, i;
	int status;
	char *buffer = NULL;
	char **input_user = NULL;
	struct stat sb;

	while (1)
	{
		write(STDOUT_FILENO, "My_simple_shell$ ", 17);
		nread = getline(&buffer, &size, stdin);
		if (nread == -1)
			break;

		numwords = countwords(buffer);

		input_user = allocatewords(buffer, numwords);

		if (numwords > 0 && stat(input_user[0], &sb) == 0 && sb.st_mode & S_IXUSR)
		{

			family_member = fork();
			if (family_member == 0)
				execve(input_user[0], input_user, NULL);
			else
				wait(&status);
		}

		for (i = 0; i < numwords; i++)
			free(input_user[i]);
		free(input_user);
	}
	free(buffer);
	write(STDOUT_FILENO, "\n", 1);

	return (0);
}
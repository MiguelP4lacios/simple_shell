#include "header_shell.h"
/**
 * _getline - reads an entire line from stream.
 * @lineptr: Doble pointer
 * @n: Numbrer of character
 * @stream: stdin.
 *
 * Return: On success Number of byte.
 * On error, -1 is returned, and errno is set appropriately.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream __attribute__((unused)))
{
	static size_t INITALLOC = 16, ALLOCSTEP = 16;
	size_t num_read = 0;
	int c = ' '; 
	ssize_t rd;

	if ((lineptr == NULL) || (n == NULL))
	{
		errno = EINVAL;
		return (-1);
	}
	if (*lineptr == NULL)
	{
		*lineptr = malloc(INITALLOC);
		if (*lineptr == NULL)
			return (-1);
		*n = INITALLOC;
	}
	while (c != EOF)
	{
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == -1)
		{
			return (-1);
		}
		num_read++;
		if (num_read >= *n)
		{
			size_t n_realloc = *n + ALLOCSTEP;
			char *tmp = _realloc(*lineptr, *n, n_realloc + 1);

			if (tmp != NULL)
				*lineptr = tmp, *n = n_realloc;
			else
				return (-1);
		}
		(*lineptr)[num_read - 1] = (char) c;
		if (c == '\n')
			break;
	}
	if (c == EOF)
	{
		errno = 0;
		return (-1);
	}
	(*lineptr)[num_read] = '\0';
	return ((ssize_t) num_read);
}


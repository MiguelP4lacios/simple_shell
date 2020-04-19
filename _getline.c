#include "header_shell.h"

/**
 * _getline - Read input of user until null
 * @buffer: buffer where input is store
 * @n: size of the buffer - unused
 * @stream: stdin - unused
 * Return: -1 if EOF (ctrl + d)
 */
ssize_t _getline(char **buffer, size_t *n, FILE *s __attribute__((unused)))
{
	int nread;
	size_t new_size = 10000;

	*buffer = _realloc(*buffer, *n, new_size);
	*n = new_size;

	nread = read(STDIN_FILENO, *buffer, new_size);
	if (nread == 0)
		nread = -1;
	return (nread);
}

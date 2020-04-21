#include "header_shell.h"

/**
 * _getline - Read input of user until null
 * @buffer: buffer where input is store
 * @n: size of the buffer - unused
 * @stream: stdin - unused
 * Return: -1 if EOF (ctrl + d)
 */
<<<<<<< HEAD
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
=======
ssize_t _getline(char **buffer, size_t *n, FILE *s __attribute__((unused)))
{
	int nread;
	size_t new_size = 10000;

	*buffer = _realloc(*buffer, *n, new_size);
	*n = new_size;
>>>>>>> d45e6e48ecde6f678d318e8e65c9d4ef6aba85b1

	nread = read(STDIN_FILENO, *buffer, new_size);
	if (nread == 0)
		nread = -1;
	return (nread);
}

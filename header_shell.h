#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/errno.h>

int strlenspace(char *s);
size_t countwords(char *input);
char **allocatewords(char *input, size_t numwords);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

#endif /* HEADER_H */

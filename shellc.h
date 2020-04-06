#ifndef SHELLCH
#define SHELLCH
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

ssize_t _getline(char **pline_buf, size_t *pn, FILE *fin);

#endif /*SHELLCH*/
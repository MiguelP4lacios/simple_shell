#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int strlenspace(char *s);
size_t countwords(char *input);
char **allocatewords(char *input, size_t numwords);

#endif

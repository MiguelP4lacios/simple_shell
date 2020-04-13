#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/errno.h>

/**
 * struct list_path - singly linked list for the path
 * @n: pointer to path value
 * @next: points to the next node
 *
 * Description: All path values connected by singly list.
 */
typedef struct list_path
{
	char *dir_path;
	struct list_path *next;
} list_path;

char **allocatewords(char *, size_t);
char *str_concat(char *, char *);
char *_getenv(const char *, char **);
list_path *add_node_end(list_path **, char *);
list_path *linked_path(char **);
size_t print_number(size_t, char *, size_t);
size_t countwords(char *, char);
size_t not_found(size_t j, char *av, char *input_user, char **);
int check_path(char **, list_path *, char *, size_t);
int strlenspace(char *);
int strlen_select(char *, char);
int _strlen(const char *);
void free_list_path(list_path *);
void execute_func(char *, char **, ssize_t, char **);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void check_built_in(char **input, char *buffer, list_path *);
int _strcmp(char *s1, char *s2);
void exit_built_in(char ** in, char *b, list_path *);
unsigned int _atoi(char *s);


#endif /* HEADER_H */

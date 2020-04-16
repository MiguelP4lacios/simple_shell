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

extern char **environ;

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

char **allocatewords(char *, size_t *, size_t);
char *str_concat(char *, char *);
char *_getenv(const char *, char **);
list_path *add_node_end(list_path **, char *);
list_path *linked_path(void);
size_t print_number(size_t, char *, size_t);
size_t countwords(char *, char);
size_t not_found(size_t j, char *av, char *input_user, char **, int);
int check_path(char **, list_path *, char *, size_t, ssize_t *);
int strlenspace(char *);
int strlen_select(char *, char);
int _strlen(const char *);
void free_list_path(list_path *);
int execute_func(char *, char **, ssize_t);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void check_built_in(char **input, char *buffer, list_path *);
int _strcmp(char *s1, char *s2);
void signal_handler(int);
size_t exit_built_in(char **in, char *b, list_path *);
unsigned int _atoi(char *s);
void print_env(void);
char **check_words(char **, size_t *, size_t);
char *realloc_special_num(size_t number, char **master, size_t i, size_t j);
int _isalpha(char c);
int _isdigit(char c);
void help_built_in(char **);
void help_exit(void);
void help_env(void);
void help_help(void);

#endif /* HEADER_H */

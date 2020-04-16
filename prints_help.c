#include "header_shell.h"
/**
 * help_exit - print how to use exit(built-in) []
 * return : nothing.
*/
void help_exit(void)
{
	char *texts = "exit: exit [STATUS]\n\tExits the shell.\n\n\tThe ";

	write(STDOUT_FILENO, texts, _strlen(texts));
	texts = "STATUS argument is the integer used to exit the shell.";
	write(STDOUT_FILENO, texts, _strlen(texts));
	texts = " If no argument is given, the command is interpreted as";
	write(STDOUT_FILENO, texts, _strlen(texts));
	texts = " exit 0.\n";
	write(STDOUT_FILENO, texts, _strlen(texts));
}
/**
 * help_env - print how to use env(built-in) []
 * return : nothing.
*/
void help_env(void)
{
	char *texts = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, texts, _strlen(texts));
}
/**
 * help_help - print how to use help(built-in) []
 * return : nothing.
*/
void help_help(void)
{
	char *texts = "help: help\n\tSee all possible Shellby builtin commands.\n";

	write(STDOUT_FILENO, texts, _strlen(texts));
	texts = "\n      help [BUILTIN NAME]\n\tSee specific information on each ";
	write(STDOUT_FILENO, texts, _strlen(texts));
	texts = "builtin command.\n";
	write(STDOUT_FILENO, texts, _strlen(texts));
}
/**
 * help_setenv - print how to use setenv(built-in) []
 * return : nothing.
*/
void help_setenv(void)
{
	char *texts = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

	write(STDOUT_FILENO, texts, _strlen(texts));
	texts = "environment variable, or modifies an existing one.\n\n";
	write(STDOUT_FILENO, texts, _strlen(texts));
	texts = "\tUpon failure, prints a message to stderr.\n";
	write(STDOUT_FILENO, texts, _strlen(texts));
}
/**
 * help_unsetenv - print how to use unsetenv(built-in) []
 * return : nothing.
*/
void help_unsetenv(void)
{
	char *text = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

	write(STDOUT_FILENO, text, _strlen(text));
	text = "environmental variable.\n\n\tUpon failure, prints a ";
	write(STDOUT_FILENO, text, _strlen(text));
	text = "message to stderr.\n";
	write(STDOUT_FILENO, text, _strlen(text));
}

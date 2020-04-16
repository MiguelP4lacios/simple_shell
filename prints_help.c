#include "header_shell.h"

/**
 * 
 * 
 * 
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

void help_env(void)
{
	char *texts = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, texts, _strlen(texts));
}

void help_help(void)
{
	char *texts = "help: help\n\tSee all possible Shellby builtin commands.\n";

	write(STDOUT_FILENO, texts, _strlen(texts));
	texts = "\n      help [BUILTIN NAME]\n\tSee specific information on each ";
	write(STDOUT_FILENO, texts, _strlen(texts));
	texts = "builtin command.\n";
	write(STDOUT_FILENO, texts, _strlen(texts));
}
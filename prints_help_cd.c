#include "header_shell.h"
/**
 * help_cd - print how to use cd(built-in) []
 * return: nothing.
*/
void help_cd(void)
{
	char *texts = "cd: cd [DIRECTORY]\n\tChanges the current directory of the";

	write(STDOUT_FILENO, texts, _strlen(texts));
	texts = " process to DIRECTORY.\n\n\tIf no argument is given, the ";
	write(STDOUT_FILENO, texts, _strlen(texts));
	texts = "command is interpreted as cd $HOME. If the argument '-' is";
	write(STDOUT_FILENO, texts, _strlen(texts));
	texts = " given, the command is interpreted as cd $OLDPWD.\n\n";
	write(STDOUT_FILENO, texts, _strlen(texts));
	texts = "\tThe environment variables PWD and OLDPWD are updated ";
	write(STDOUT_FILENO, texts, _strlen(texts));
	texts = "after a change of directory.\n";
	write(STDOUT_FILENO, texts, _strlen(texts));
}
/**
 * help - print how to use help(built-in) []
 * return: nothing.
*/
void help(void)
{
	char *texts = "hsh\nThese shell commands are defined internally.\n";

	write(STDOUT_FILENO, texts, _strlen(texts));
	texts = "Type 'help' to see this list.\nType 'help name' to find ";
	write(STDOUT_FILENO, texts, _strlen(texts));
	texts = "out more about the function 'name'.\n\n  cd    \tcd ";
	write(STDOUT_FILENO, texts, _strlen(texts));
	texts = "[DIRECTORY]\n  exit    \texit [STATUS]\n  env     \tenv";
	write(STDOUT_FILENO, texts, _strlen(texts));
	texts = "\n  setenv  \tsetenv [VARIABLE] [VALUE]\n  unsetenv\t";
	write(STDOUT_FILENO, texts, _strlen(texts));
	texts = "unsetenv [VARIABLE]\n";
	write(STDOUT_FILENO, texts, _strlen(texts));
}

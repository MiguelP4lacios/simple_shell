#include "header_shell.h"
/**
 * signal_handler - print prompt again when signal-control-c
 * @signal: unused
 */
void signal_handler(int signal __attribute__((unused)))
{
	write(STDOUT_FILENO, "\n$ ", 3);
}

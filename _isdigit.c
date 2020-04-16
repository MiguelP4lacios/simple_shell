#include "header_shell.h"

/**
  *_isdigit - Check if a character is number
  *@c: char to be check
  *Return: 1 if letter, 0 if not
  */
int _isdigit(char c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

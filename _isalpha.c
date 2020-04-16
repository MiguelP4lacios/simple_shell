#include "header_shell.h"
/**
  *_isalpha - Check if a character is a letter
  *@c: char to be check
  *Return: 1 if letter, 0 if not
  */
int _isalpha(char c)
{
	int i;
	char alp[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (i = 0; alp[i] != '\0'; i++)
	{
		if (alp[i] == c)
			return (1);
	}

	return (0);
}

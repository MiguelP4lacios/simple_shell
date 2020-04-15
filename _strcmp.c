#include "header_shell.h"
/**
  * _strcmp - compares two strings.
  * @s1: 1th string.
  * @s2: 2th string.
  * Return: integer
  */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	else
		return ((int)(*s1 - *s2));
}

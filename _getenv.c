#include "header_shell.h"

/**
 * _getenv - get environment variable
 * @name: name of the variable
 * Return: Pointer to location of variable
 */
char *_getenv(const char *name)
{
	int len, flag, i, j;

	len = _strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; j < len; j++)
		{
			if (name[j] == environ[i][j])
				flag = 1;
			else
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1 && environ[i][j] == '=')
			return (&environ[i][j + 1]);
		}
	return (NULL);
}

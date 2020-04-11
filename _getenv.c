#include "header_shell.h"

/**
 * _getenv - get environment variable
 * @name: name of the variable
 * @env: enviornment
 * Return: Pointer to location of variable
 */
char *_getenv(const char *name, char **env)
{
	int len, flag, i, j;
	char *p = NULL;

	len = _strlen(name);

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < len; j++)
		{
			if (name[j] == env[i][j])
				flag = 1;
			else
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1 && env[i][j] == '=')
		{
			p = &env[i][j] + 1;
			return (p);
		}
	}
	return (NULL);
}

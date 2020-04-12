/**
 * strlen_select - Counts characters until null or the select char is found
 * @s: Pointer to string to be count
 * @select: select char. Stop counting process when found
 * Return: Number of characters count
 */
int strlen_select(char *s, char select)
{
	int i;

	for (i = 0; s[i] != '\0' && s[i] != select && s[i] != '\n'; i++)
	{
	}
	return (i);
}

/**
 * strlen_select - Counts characters until null or the select char is found
 * @s: Pointer to string to be count
 * @c: select char. Stop counting process when found
 * Return: Number of characters count
 */
int strlen_select(char *s, char c)
{
	int i;
	char select2 = c;

	if (c == ' ')
		select2 = 9;
	for (i = 0; s[i] != '\0' && s[i] != c && s[i] != select2 && s[i] != '\n'; i++)
	{
	}
	return (i);
}

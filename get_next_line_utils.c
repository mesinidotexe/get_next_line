#include "get_next_line.h"

size_t	line_len(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

size_t	line_chr(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (1);
	return (0);
}

char *cleanbuff(char *buffer)
{
	buffer[0] = '\0';
	return (buffer);
}

char	*gnl_join(char *s1, char *buffer)
{
	size_t	i;
	int		j;
	char	*newstr;
	int		size;

	size = 0;
	if (s1)
		size = line_len(s1);
	i = 0;
	j = 0;
	newstr = malloc(size + line_len(buffer) + 1);
	if (!newstr)
		return (NULL);
	while (s1 && s1[i] != 0)
	{
		newstr[i] = s1[i];
		i++;
	}
	free(s1);
	while (i < line_len(buffer))
	{
		newstr[i] = buffer[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}

#include "get_next_line.h"

size_t	line_len(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
	{
		i++;
	}
	if (s[i] == '\n')
	{
		i++;
	}
	return (i);
}
size_t	line_chr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
	{
		i++;
	}
	if (s[i] == '\n')
		return (1);
	return (0);
}

void	cleanbuff(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i])
	{
		buffer[j] = buffer[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
}

char	*gnl_join(char *s1, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*newstr;

	i = 0;
	j = 0;
	newstr = malloc(line_len(s1) + line_len(buffer) + 1);
	if (!newstr)
		return (NULL);
	while (s1 && s1[i] != '\0' && i < line_len(s1))
	{
		newstr[i] = s1[i];
		i++;
	}
	free(s1);
	while (buffer[j] && j < line_len(buffer))
	{
		newstr[i] = buffer[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}

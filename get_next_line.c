/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 23:32:51 by vmesini-          #+#    #+#             */
/*   Updated: 2025/11/17 23:32:53 by vmesini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	line = NULL;
	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	while (!line_chr(line))
	{
		if (buffer[0] == '\0')
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
		}
		line = gnl_join(line, buffer);
		return (line);
	}
	return (line);
}

int	main(void)
{
	int		fd;

	fd = open("a.txt", O_RDONLY);
	return (0);
}

// if (bytes_read < 0)
// 	return (free(line), NULL);
// if (bytes_read == 0)
// 	return (line);

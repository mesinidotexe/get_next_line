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
	int		reads;
	char	*str;

	reads = 1;
	if (fd < 0 || fd >= FOPEN_MAX)
		return (NULL);
	while (1)
	{
		reads = read(fd, buffer, BUFFER_SIZE);
		if (reads < 0)
			return (NULL);
		if (!reads)
			return (NULL);
		// if (read == '\n')
		// 	break;
		printf("%s\n", buffer);
	}
	buffer[BUFFER_SIZE] = '\0';
	printf("buffer : %s\n", buffer);
}
int main()
{
	int	fd;

	fd = open("a.txt", O_RDONLY);
	get_next_line(fd);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:44:34 by sbenitez          #+#    #+#             */
/*   Updated: 2024/07/04 13:56:38 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t		bytes_read = 0;
	char		*buf;
	static char	*temp;

	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	while (buf[bytes_read] != '\n')
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		buf = ft_strjoin(buf, temp);
	}
	if (bytes_read <= 0)
		return ((free(buf)), NULL);
	return (buf);
}


#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int		fd;
	char	*line;
	
	if (argc != 2)
		return (1);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("42:\n%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:44:34 by sbenitez          #+#    #+#             */
/*   Updated: 2024/07/05 15:47:55 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_buffer(int fd, char **buf, ssize_t *bytes_read)
{
	*buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	bytes_read += read(fd, *buf, BUFFER_SIZE);
	if ((ssize_t)bytes_read <= 0)
		return ((free(*buf)), *buf = NULL, (NULL));
	return (*buf);
}

char	*get_next_line(int fd)
{
	ssize_t		bytes_read;
	int			i;
	static char	*buf;

	bytes_read = 0;
	i = 0;
	if (!read_to_buffer(fd, &buf, &bytes_read))
		return (NULL);
	while (buf[i] != '\n')
	{
		while (i < bytes_read)
			i++;
	}
	buf[bytes_read] = '\0';
	return (buf);
}

#include <fcntl.h>
#include <stdio.h> 

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("42: %s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}